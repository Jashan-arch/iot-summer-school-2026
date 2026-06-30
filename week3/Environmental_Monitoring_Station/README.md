# Environmental Monitoring Station

## Hardware Used

- Arduino Uno
- DHT22 Temperature and Humidity Sensor
- Red LED
- Green LED
- 220 Ω Resistors
- Breadboard
- Jumper Wires

## Description

This project measures temperature and humidity using a DHT22 sensor every 2 seconds. Data is displayed on the Serial Monitor in CSV format. A red LED indicates high temperature (>35°C) or high humidity (>80%), while a green LED indicates normal environmental conditions.

## CSV Output Format

timestamp,temp_C,temp_F,humidity

## Library

DHT sensor library by Adafruit

Library Version: 1.4.6

## Files

- Environmental_Monitoring_Station.ino
- sample_readings.csv
