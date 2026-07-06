# MQTT Sensor Publisher (ESP32)

## Project Overview

This project demonstrates an Internet of Things (IoT) application using an ESP32, MQTT protocol, and a DHT22 sensor. The ESP32 connects to a Wi-Fi network, reads temperature and humidity data every 5 seconds, and publishes the readings in JSON format to a public MQTT broker. It also subscribes to an MQTT topic that allows remote control of the onboard LED.

---

## Objectives

* Connect ESP32 to a Wi-Fi network.
* Read temperature and humidity from the sensor.
* Publish sensor data to a public MQTT broker every 5 seconds.
* Format data as JSON.
* Subscribe to an LED control topic.
* Toggle the onboard LED based on received MQTT messages.
* Verify communication using MQTT Explorer or a web-based MQTT client.

---

## Hardware Required

* ESP32 Development Board
* DHT22 Sensor 
* Breadboard 
* Jumper Wires

---

## Software Required

* Arduino IDE 2.x
* ESP32 Board Package
* Wokwi Simulator
* MQTT Explorer or HiveMQ Web Client
* Arduino Libraries:

  * WiFi
  * PubSubClient
  * ArduinoJson
  * DHTesp

---

## Circuit Connections

| Component   | ESP32 Pin |
| ----------- | --------- |
| DHT22 VCC   | 3.3V      |
| DHT22 GND   | GND       |
| DHT22 DATA  | GPIO 15   |
| Onboard LED | GPIO 2    |

---

## MQTT Broker Details

**Broker**

```
broker.hivemq.com
```

**Port**

```
1883
```

---

## MQTT Topics

### Temperature

```
iitjammu/summer26/ShubhJashanSingh/temperature
```

### Humidity

```
iitjammu/summer26/ShubhJashanSingh/humidity
```

### LED Control

```
iitjammu/summer26/ShubhJashanSingh/led_control
```

---

## JSON Message Format

### Temperature

```json
{
  "value": 28.5,
  "unit": "C",
  "ts": 123456
}
```

### Humidity

```json
{
  "value": 64.3,
  "unit": "%",
  "ts": 123456
}
```

---

## Project Features

* Wi-Fi connectivity using ESP32
* MQTT communication
* JSON data publishing
* Temperature monitoring
* Humidity monitoring
* Remote LED control
* Serial Monitor debugging
* Compatible with Wokwi simulation

---

## How It Works

1. ESP32 connects to the Wi-Fi network.
2. ESP32 connects to the HiveMQ public MQTT broker.
3. Every 5 seconds:

   * Read temperature.
   * Read humidity.
   * Create JSON payloads.
   * Publish both values to their respective MQTT topics.
4. ESP32 continuously listens for messages on the LED control topic.
5. Receiving **ON** turns the onboard LED ON.
6. Receiving **OFF** turns the onboard LED OFF.

---

## How to Test

1. Open the project in Wokwi.
2. Start the simulation.
3. Open the Serial Monitor (115200 baud).
4. Wait until Wi-Fi and MQTT connections are established.
5. Open MQTT Explorer or the HiveMQ Web Client.
6. Connect to **broker.hivemq.com** on port **1883**.
7. Subscribe to:

```
iitjammu/summer26/ShubhJashanSingh/#
```

8. Observe temperature and humidity messages arriving every 5 seconds.
9. Publish **ON** or **OFF** to:

```
iitjammu/summer26/ShubhJashanSingh/led_control
```

10. Verify that the ESP32 onboard LED changes state.

---

## Expected Serial Monitor Output

```
WiFi Connected
Connecting MQTT...
Connected

Published Temperature:
{"value":27.8,"unit":"C","ts":5000}

Published Humidity:
{"value":64.2,"unit":"%","ts":5000}

Message Received: ON
LED ON

Message Received: OFF
LED OFF
```

---

## Troubleshooting

* Verify the Wi-Fi SSID and password are correct.
* Ensure the MQTT broker address is **broker.hivemq.com** and port **1883**.
* Confirm the topic names match exactly in both the ESP32 code and MQTT client.
* Check that the required Arduino libraries are installed.
* Ensure the Wokwi simulation is running before attempting to subscribe or publish.

---

## Future Improvements

* Add support for multiple sensors.
* Publish additional environmental data such as pressure or light intensity.
* Store sensor readings in a cloud database.
* Add TLS encryption for secure MQTT communication.
* Create a mobile dashboard for real-time monitoring.

---

## Author

**Name:** Shubh Jashan Singh
