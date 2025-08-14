# Industrial Monitoring System using LPC1768 Microcontroller

## Overview
This project is an **embedded industrial safety monitoring system** developed as part of the IIES Embedded Systems program.  
It uses the **LPC1768 ARM Cortex-M3 microcontroller** to detect and respond to safety hazards such as:
- Helmet detection for workers
- Gas leak detection
- Fire detection
- Temperature monitoring

When hazards are detected, the system triggers visual and audible alerts using a buzzer and relay, and displays relevant information on an LCD.

---

## Features
- **Helmet Detection (IR Sensor):** Ensures workers wear helmets before operating machinery.
- **Gas Leak Detection (Gas Sensor):** Detects the presence of harmful gases.
- **Fire Detection (Flame Sensor):** Triggers buzzer alerts when fire is detected.
- **Temperature Monitoring (ADC):** Monitors real-time temperature and activates relay/buzzer if above threshold.
- **LCD Interface:** Displays current status and sensor readings.

---

## Hardware Components
- **LPC1768 ARM Cortex-M3 Microcontroller**
- IR Sensor for helmet detection
- Gas Sensor (MQ series)
- Flame Sensor
- Temperature Sensor (LM35)
- Buzzer
- Relay
- 16x2 LCD Display

---

## Software & Tools
- Embedded C
- Keil uVision IDE
- LPC17xx Peripheral Library
- ARM GCC Toolchain

---

## How It Works
1. **Helmet Check:** Uses IR sensor to verify if a helmet is worn.
2. **Fire Check:** Reads flame sensor input and triggers alarm if fire is detected.
3. **Gas Check:** Reads gas sensor input to detect leaks.
4. **Temperature Monitoring:** Uses ADC to convert temperature sensor readings to Celsius.
5. **Alert System:** Activates buzzer and relay when any hazard exceeds set thresholds.

---

## Circuit & Pin Configuration
- **IR Sensor:** P1.1
- **Fire Sensor:** P1.9
- **Gas Sensor:** P1.4
- **Temperature Sensor (ADC0.2):** P0.25
- **Buzzer:** P1.27
- **Relay:** P1.28
- **LCD Data Pins:** P0.15–P0.22
- **LCD Control Pins:** RS (P0.10), EN (P0.11)

---

## Repository Structure
