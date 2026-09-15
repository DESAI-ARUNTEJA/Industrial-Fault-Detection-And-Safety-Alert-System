# 🏭 INDUSGUARD - Industrial Fault Detection and Safety Alert System 🚨

![Platform](https://img.shields.io/badge/Platform-ARM7%20LPC2148-blue)
![Language](https://img.shields.io/badge/Language-Embedded%20C-green)
![Protocol](https://img.shields.io/badge/Communication-GSM%20%7C%20UART-orange)
![Status](https://img.shields.io/badge/Status-Completed-success)

---

## 📖 About

**INDUSGUARD** is an Embedded Systems project designed to provide **real-time industrial fault detection and safety monitoring**. The system continuously monitors environmental parameters and sends alert messages through GSM whenever abnormal conditions are detected.

It is built around the **LPC2148 ARM7 Microcontroller** and uses **DHT11**, **EEPROM**, **LCD**, **GSM Module**, **RTC**, and **Keypad** for monitoring and secure user interaction.

---

## ✨ Features

🔹 Real-Time Temperature Monitoring 🌡️  
🔹 Humidity Monitoring 💧  
🔹 GSM Based SMS Alert System 📱  
🔹 EEPROM Data Storage 💾  
🔹 Password Protected Access 🔐  
🔹 RTC Timestamp Support ⏰  
🔹 Local Parameter Configuration ⌨️  
🔹 Remote Configuration Through SMS 📩  
🔹 Fault Indication Using LEDs 🚨  
🔹 Industrial Safety Monitoring 🏭

---

## 🛠 Hardware Components

- ⚡ LPC2148 ARM7 Microcontroller
- 🌡 DHT11 Sensor
- 📟 16×2 LCD Display
- 💾 AT24C256 EEPROM
- 📱 GSM Module (M660A)
- ⌨️ 4×4 Matrix Keypad
- 💡 LEDs
- 🔘 Switches
- 🔌 USB-UART Converter

---

## 💻 Software Used

- 🖥 Keil μVision
- 🔥 Flash Magic
- ⚙ Embedded C
- 📡 UART Communication
- 🔄 I2C Protocol

---

## 📂 Project Structure

```text
INDUSGUARD
│
├── main.c
├── pro_main.c
├── dummy_pro_main.c
│
├── lcd.c
├── lcd.h
├── lcd1.c
│
├── delay.c
├── delay.h
│
├── dht11.c
├── dht11.h
│
├── GSM.c
├── GSM.h
│
├── UART_INT.c
├── UART_INT.h
├── uart0.h
│
├── rtc.c
├── rtc.h
├── rtc_defines.h
│
├── i2c_peripheral.c
├── i2c_eeprom.c
├── i2c_eeprom.h
├── i2c.h
├── i2c_defines.h
├── i2c_eeprom_defines.h
│
├── kpm.c
├── kpm.h
├── kpm_defines.h
│
├── edit.c
├── edit.h
│
├── exint.c
│
├── defines.h
├── types.h
│
└── README.md
```

---

## ⚙️ Working Principle

```text
DHT11 Sensor
      │
      ▼
LPC2148 Microcontroller
      │
 ┌────┼────┬───────┐
 ▼    ▼    ▼       ▼
LCD EEPROM GSM    RTC
Display Storage SMS Timestamp
      │
      ▼
Fault Detection
      │
      ▼
Alert Message Sent
```

## 🏗️ Block Diagram


<img width="777" height="729" alt="image" src="https://github.com/user-attachments/assets/45711989-631a-4854-849a-7ea48f32dbb4" />

---

## 🔌 Peripheral Interfaces

| Peripheral | Interface |
|-------------|-----------|
| 📱 GSM Module (M660A) | UART |
| 💾 AT24C256 EEPROM | I2C |
| 🌡️ DHT11 Sensor | GPIO |
| 📟 LCD Display | GPIO |
| ⌨️ 4×4 Matrix Keypad | GPIO |
| ⏰ RTC | Internal RTC |
| 🔘 Switch | External Interrupt (EINT0) |

---

## 📱 SMS Commands

### 🌡 Change Temperature Threshold

```text
0786T38$
```

### 📞 Update Mobile Number

```text
0786M9876543210$
```

### 📊 Request Sensor Information

```text
0786I$
```

---

## 🔐 Security Features

✅ Password Protected Access 🔑

✅ Authorized Mobile Number Verification 📱

✅ EEPROM-Based Secure Storage 💾

✅ Wrong Password Detection 🚫

✅ System Lock After Multiple Incorrect Attempts 🔒

---

## 🚀 Modules Implemented

### 📟 LCD Interface
- Character Display
- String Display
- Integer Display

### 🌡 DHT11 Driver
- Temperature Reading
- Humidity Reading

### 📱 GSM Module
- SMS Send
- SMS Receive
- AT Commands

### 💾 EEPROM Interface
- Byte Write
- Byte Read
- Page Write
- Sequential Read

### ⌨️ Keypad Interface
- Password Entry
- Menu Navigation

### ⏰ RTC Module
- Date and Time Stamp

### 📡 UART Interrupt
- Interrupt Driven Communication

### 🔄 I2C Communication
- EEPROM Communication

### 🚨 External Interrupt
- Local Configuration Mode

---

## 🎯 Applications

🏭 Industrial Monitoring

⚙ Machine Safety Systems

🌡 Temperature Monitoring

💧 Humidity Monitoring

🚨 Fault Detection Systems

📱 Remote Alert Systems

🏢 Smart Factory Automation

---

## 👩‍💻 Project Presented By

### **CH LAKSHMI SWAMY**

B.Tech Electronics and Communication Engineering (ECE)

Vector India Major Project

Embedded Systems | LPC2148 | I2C

---
