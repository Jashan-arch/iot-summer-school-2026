# Wi-Fi Temperature Monitor (ESP32)

## Project Overview

This project creates a web-based environmental monitoring system using an ESP32 and a DHT22 sensor. The ESP32 connects to a Wi-Fi network and hosts a web page that displays live temperature and humidity readings.

The web page automatically refreshes every 10 seconds and allows the user to control an LED remotely. The page also displays the device uptime.

## Hardware Required

* ESP32 Development Board
* DHT22 Sensor
* LED
* 220 Ω Resistor
* Breadboard
* Jumper Wires
* Wi-Fi Network

## Circuit Connections

### DHT22

| DHT22 Pin | ESP32 Pin |
| --------- | --------- |
| VCC       | 3.3V      |
| GND       | GND       |
| DATA      | GPIO 4    |

### LED

| LED Pin     | ESP32 Pin                  |
| ----------- | -------------------------- |
| Anode (+)   | GPIO 2                     |
| Cathode (-) | GND through 220 Ω resistor |

## Features

* Wi-Fi connectivity
* Embedded web server
* Live temperature monitoring
* Live humidity monitoring
* Auto refresh every 10 seconds
* Remote LED control
* Device uptime display

## How to Use

1. Open the Arduino IDE.
2. Install the ESP32 board package.
3. Install the DHT sensor library.
4. Enter your Wi-Fi SSID and password in the code.
5. Upload the sketch to the ESP32.
6. Open the Serial Monitor at 115200 baud.
7. Note the IP address printed by the ESP32.
8. Enter the IP address into a web browser.
9. View temperature, humidity, uptime, and LED status.
10. Use the Toggle LED button to control the LED.

## Libraries Used

* WiFi.h
* WebServer.h
* DHT.h

## Author

Shubh Jashan Singh
