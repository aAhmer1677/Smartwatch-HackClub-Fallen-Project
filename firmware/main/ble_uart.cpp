#include "ble_uart.h"

#include "esp_log.h"
#include "esp_nimble_hci.h"
#include "nvs_flash.h"
#include "nimble/nimble_port.h"
#include "nimble/nimble_port_freertos.h"
#include "host/ble_hs.h"
#include "host/ble_uuid.h"
#include "host/util/util.h"
#include "services/gap/ble_svc_gap.h"
#include "services/gatt/ble_svc_gatt.h"
#include "smartwatch.h"

#include <cstdarg>
#include <cstdio>
#include <cstring>

namespace ble_uart {

namespace {
constexpr char TAG[] = "ble_uart";
static uint16_t tx_handle;
static uint16_t notify_handle;
static uint16_t connection_handle = BLE_HS_CONN_HANDLE_NONE;

static ble_uuid128_t svc_uuid = BLE_UUID128_INIT(
    0x9e, 0xca, 0xdc, 0x24, 0x0e, 0xe5, 0xa9, 0xe0,
    0x93, 0xf3, 0xa3, 0xb5, 0x01, 0x00, 0x40, 0x6e);
static ble_uuid128_t rx_uuid = BLE_UUID128_INIT(
    0x9e, 0xca, 0xdc, 0x24, 0x0e, 0xe5, 0xa9, 0xe0,
    0x93, 0xf3, 0xa3, 0xb5, 0x02, 0x00, 0x40, 0x6e);
static ble_uuid128_t tx_uuid = BLE_UUID128_INIT(
    0x9e, 0xca, 0xdc, 0x24, 0x0e, 0xe5, 0xa9, 0xe0,
    0x93, 0xf3, 0xa3, 0xb5, 0x03, 0x00, 0x40, 0x6e);

static int gap_event(struct ble_gap_event *event, void *) {
    switch (event->type) {
    case BLE_GAP_EVENT_CONNECT:
        connection_handle = event->connect.status == 0 ? event->connect.conn_handle : BLE_HS_CONN_HANDLE_NONE;
        if (event->connect.status == 0) ble_gap_security_initiate(connection_handle);
        break;
    case BLE_GAP_EVENT_DISCONNECT:
        connection_handle = BLE_HS_CONN_HANDLE_NONE;
    {
        ble_gap_adv_params adv_params{};
        adv_params.conn_mode = BLE_GAP_CONN_MODE_UND;
        adv_params.disc_mode = BLE_GAP_DISC_MODE_GEN;
        ble_gap_adv_start(BLE_OWN_ADDR_PUBLIC, nullptr, BLE_HS_FOREVER,
                          &adv_params, gap_event, nullptr);
    }
        break;
    default:
        break;
    }
    return 0;
}

static int access_cb(uint16_t, uint16_t attr_handle,
                     struct ble_gatt_access_ctxt *context, void *) {
    if (context->op == BLE_GATT_ACCESS_OP_WRITE_CHR) {
        char buffer[64];
        uint16_t length = OS_MBUF_PKTLEN(context->om);
        if (length >= sizeof(buffer)) length = sizeof(buffer) - 1;
        ble_hs_mbuf_to_flat(context->om, buffer, length, nullptr);
        buffer[length] = '\0';
        ESP_LOGI(TAG, "RX: %s", buffer);
        if (strncasecmp(buffer, "HAPTIC", 6) == 0) {
            smartwatch::haptic_pulse(80);
        } else if (strncasecmp(buffer, "STATUS", 6) == 0) {
            smartwatch::State state;
            smartwatch::get_state(state);
            txf("STATUS batt=%lu mv acc=%ld,%ld,%ld",
                static_cast<unsigned long>(state.battery_mv),
                static_cast<long>(state.accel_mg[0]),
                static_cast<long>(state.accel_mg[1]),
                static_cast<long>(state.accel_mg[2]));
        }
    }
    if (context->op == BLE_GATT_ACCESS_OP_READ_CHR && attr_handle == tx_handle) {
        const char state[] = "READY";
        os_mbuf_append(context->om, state, sizeof(state) - 1);
    }
    return 0;
}

static ble_gatt_chr_def characteristics[] = {
    {&rx_uuid.u, access_cb, nullptr, nullptr,
     BLE_GATT_CHR_F_WRITE | BLE_GATT_CHR_F_WRITE_NO_RSP,
     0, nullptr, nullptr},
    {&tx_uuid.u, access_cb, nullptr, nullptr,
     BLE_GATT_CHR_F_NOTIFY, 0, &tx_handle, nullptr},
    {}
};

static ble_gatt_svc_def service[] = {
    {BLE_GATT_SVC_TYPE_PRIMARY, &svc_uuid.u, nullptr, characteristics},
    {}
};

static void start_advertising() {
    ble_hs_adv_fields fields{};
    fields.flags = BLE_HS_ADV_F_DISC_GEN | BLE_HS_ADV_F_BREDR_UNSUP;
    fields.tx_pwr_lvl_is_present = 1;
    fields.name = reinterpret_cast<const uint8_t *>("Smartwatch");
    fields.name_len = 10;
    fields.name_is_complete = 1;
    ble_gap_adv_set_fields(&fields);

    ble_uuid128_t &uuid = svc_uuid;
    ble_hs_adv_fields scan_fields{};
    scan_fields.uuids128 = &uuid;
    scan_fields.num_uuids128 = 1;
    scan_fields.uuids128_is_complete = 1;
    ble_gap_adv_rsp_set_fields(&scan_fields);

    ble_gap_adv_params adv_params{};
    adv_params.conn_mode = BLE_GAP_CONN_MODE_UND;
    adv_params.disc_mode = BLE_GAP_DISC_MODE_GEN;
    ble_gap_adv_start(BLE_OWN_ADDR_PUBLIC, nullptr, BLE_HS_FOREVER, &adv_params, gap_event, nullptr);
}

static void on_sync(void) {
    ble_hs_id_infer_auto(0, nullptr);
    start_advertising();
}

static void host_task(void *) {
    nimble_port_run();
}

} // namespace

void init() {
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        nvs_flash_erase();
        nvs_flash_init();
    }

    nimble_port_init();
    ble_hs_cfg.sync_cb = on_sync;
    ble_svc_gap_init();
    ble_svc_gatt_init();
    ble_svc_gap_device_name_set("Smartwatch");

    characteristics[0].val_handle = nullptr;
    service[0].characteristics = characteristics;
    ble_gatts_count_cfg(service);
    ble_gatts_add_svcs(service);

    nimble_port_freertos_init(host_task);
}

bool connected() {
    return connection_handle != BLE_HS_CONN_HANDLE_NONE;
}

void tx(const char *text) {
    if (!connected() || text == nullptr) return;
    struct os_mbuf *om = os_msys_get_pkthdr(strlen(text), 0);
    if (!om) return;
    os_mbuf_append(om, text, strlen(text));
    ble_gatts_notify_custom(connection_handle, tx_handle, om);
}

void txf(const char *format, ...) {
    char buffer[160];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    tx(buffer);
}

} // namespace ble_uart
