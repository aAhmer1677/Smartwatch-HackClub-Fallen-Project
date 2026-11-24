# Smartwatch // HackClub Fallen Project

[![Hack Club Fallen](https://img.shields.io/badge/Hack%20Club-Fallen-FF4747?style=for-the-badge)](https://fallen.hackclub.com/)

An open-source smartwatch built from scratch for the Hack Club Fallen. It runs on bare-metal ESP32-S3 with [[additional functions to be added]]

## The Backstory
Smartwatches have potential: You can strap them to your wrist and wear them everywhere. 

This smartwatch could:
- **Launch a private gateway:** you and your friends can then play in class.
- **Allow WIFI Connection to Your Mobile:** useful for that day you forgot your phone (basically calling with no additional sim card).
- **and much more**

I wanted to build a project so that other devs around the world can build upon this watch, including cool and interesting features that I couldn't have come up with myself.

## Compilation & Development

### We will be using:
- **ESP-IDF** - to compile and flash the firmware to the ESP32-S3
- **Android Studio** - to build and flash the Smartwatch App to our Android device *Samsung Galaxy A37 5G in my case*
- **EEZ Studio** - to create and compile the UI in LVGL
- **VS Code** - as the IDE for our overall project

### 1. Flash the firmware to the custom PCB

**Set the target device as an ESP32-S3**
```powershell
idf.py set-target esp32s3
```

**Open the built in terminal menu to configure variables**
```powershell
idf.py menuconfig
```

**Firmware Compilation**
```powershell
idf.py build
```

**Firmware Flashing & Serial Monitoring**
```powershell
# Replace COM3 with your own port
idf.py -p COM3 flash monitor
```


## File Structure
[To be finalised]

```text
Smartwatch Project
├── .github/
├── 3d-models/
|   ├── Chasis/
|   ├── Desings/
|   ├── Strap/
|   └── to print/
├── Android App/
├── assets/
|   ├── plan/
|   └── README/
├── PCB and Schematics/
├── firmware/
|   ├── managed-components/
|   ├── ui/
|   ├── CMakeLists.txt
|   ├── idf_component.yml
|   └── sdkconfig
├── .env.example
├── .gitignore
├── BOM.csv
├── LICENSE
├── plan.md
└── README.md
```

---
## The Project Plan
[`plan.md`](plan.md)

## Images of Product
### 3D Designs
<img src="assets/README/PCB 3D View.png" alt="PCB CAD 3D Model" width="100">
<img src="assets/README/Chassis Assembled.png" alt="Chassis 3D Model" width="100">
<img src="assets/README/Strap Assembled.png" alt="Strap 3D Model" width="100">
<img src="assets/README/Strap Long Assembled.png" alt="Long Strap 3D Model" width="100">
<img src="assets/README/Strap Short Assembled.png" alt="Short Strap 3D Model" width="100">

## To Print
- ☐ Smartwatch chasis backplate
- ☐ Smartwatch chasis body
- ☐ Smartwatch strap long black + white mold
- ☐ Smartwatch strap long black mold
- ☐ Smartwatch strap short black + white mold
- ☐ Smartwatch strap short black mold
- ☐ Smartwatch strap short pin
- ☑






---

Built by Abdullah Ahmer for **Hack Club Fallen**
