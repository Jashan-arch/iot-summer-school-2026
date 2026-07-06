# Bluetooth Sensor Dashboard (ESP32 BLE)

## Project Overview

This project demonstrates how to build a Bluetooth Low Energy (BLE) sensor dashboard using an ESP32 microcontroller and a DHT11 temperature and humidity sensor. The ESP32 reads environmental data every 3 seconds and broadcasts it over BLE using custom GATT characteristics. A BLE scanner application such as **nRF Connect** or **LightBlue** can connect to the ESP32 and view the live sensor readings.

---

## Objectives

- Read temperature and humidity from a DHT11 sensor.
- Broadcast sensor values over Bluetooth Low Energy (BLE).
- Update sensor values every 3 seconds.
- Implement a BLE GATT Service with multiple characteristics.
- Add descriptors to each characteristic for BLE compatibility.
- Monitor sensor data using a BLE scanner application.

---

## Hardware Required

| Component | Quantity |
|----------|----------|
| ESP32 Development Board | 1 |
| DHT11 Temperature & Humidity Sensor | 1 |
| Breadboard | 1 |
| Jumper Wires | As required |
| USB Cable | 1 |

---

## Software Required

- Arduino IDE 2.x
- ESP32 Board Package
- DHT Sensor Library by Adafruit
- Adafruit Unified Sensor Library
- BLE Library (included with ESP32 Board Package)
- nRF Connect (Android/iOS)
- LightBlue (Android/iOS)

---

## Circuit Connections

| DHT11 Pin | ESP32 Pin |
|-----------|-----------|
| VCC | 3.3V |
| GND | GND |
| DATA | GPIO 4 |

---

## BLE Configuration

### Device Name

```
ESP32_DHT11
```

### BLE Service UUID

```
12345678-1234-1234-1234-1234567890AB
```

---

## GATT Characteristics

| Characteristic | UUID | Property |
|---------------|------|----------|
| Temperature | 12345678-1234-1234-1234-1234567890AC | Read, Notify |
| Humidity | 12345678-1234-1234-1234-1234567890AD | Read, Notify |
| Timestamp | 12345678-1234-1234-1234-1234567890AE | Read, Notify |

Each characteristic includes a **BLE2902 descriptor** to support notifications and improve compatibility with BLE scanner applications.

---

## Working Principle

1. ESP32 initializes Bluetooth Low Energy.
2. A BLE Service is created.
3. Three GATT Characteristics are created:
   - Temperature
   - Humidity
   - Timestamp
4. ESP32 advertises the BLE Service.
5. Every 3 seconds:
   - Read temperature from DHT11.
   - Read humidity from DHT11.
   - Read current timestamp using `millis()`.
   - Update BLE characteristics.
   - Send notifications to connected devices.

---

## Data Broadcast Format

Example:

Temperature

```
28.6
```

Humidity

```
63.0
```

Timestamp

```
12000
```

---

## Serial Monitor Output

Example:

```
BLE Sensor Started

Temperature: 28.5 C
Humidity: 65.0 %
Timestamp: 3000 ms

Temperature: 28.7 C
Humidity: 64.0 %
Timestamp: 6000 ms

Temperature: 28.8 C
Humidity: 64.0 %
Timestamp: 9000 ms
```

---

## Testing Procedure

1. Upload the code to the ESP32.
2. Open the Serial Monitor (115200 baud).
3. Open **nRF Connect** or **LightBlue** on your smartphone.
4. Enable Bluetooth.
5. Scan for BLE devices.
6. Select **ESP32_DHT11**.
7. Open the advertised service.
8. Observe the Temperature, Humidity, and Timestamp characteristics.
9. Verify that the values update every 3 seconds.

## Libraries Used

- DHT Sensor Library by Adafruit
- Adafruit Unified Sensor Library
- BLEDevice
- BLEServer
- BLEUtils
- BLE2902

---

## Features

- Bluetooth Low Energy (BLE)
- ESP32 GATT Server
- Multiple BLE Characteristics
- BLE Notifications
- DHT11 Temperature Monitoring
- Humidity Monitoring
- Timestamp Logging
- Live Data Updates
- Custom UUIDs
- Modular Code Design

---

## Future Improvements

- Add support for DHT22.
- Display data on an OLED display.
- Log sensor data to an SD card.
- Publish sensor data to an MQTT broker over Wi-Fi.
- Develop a custom Android application.
- Add battery level monitoring.
