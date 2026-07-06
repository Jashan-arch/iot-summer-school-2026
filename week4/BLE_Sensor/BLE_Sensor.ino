/*
-------------------------------------------------------
Project: Bluetooth Sensor Dashboard (ESP32 BLE)
Author: Shubh Jashan Singh
Date: 30-06-2026
-------------------------------------------------------
*/

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// Service UUID
#define SERVICE_UUID        "12345678-1234-1234-1234-1234567890AB"

// Characteristic UUIDs
#define TEMP_UUID           "12345678-1234-1234-1234-1234567890AC"
#define HUM_UUID            "12345678-1234-1234-1234-1234567890AD"
#define TIME_UUID           "12345678-1234-1234-1234-1234567890AE"

BLECharacteristic *tempChar;
BLECharacteristic *humChar;
BLECharacteristic *timeChar;

void setup() {

  Serial.begin(115200);

  dht.begin();

  BLEDevice::init("ESP32_DHT11");

  BLEServer *server = BLEDevice::createServer();

  BLEService *service = server->createService(SERVICE_UUID);

  tempChar = service->createCharacteristic(
      TEMP_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY);

  humChar = service->createCharacteristic(
      HUM_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY);

  timeChar = service->createCharacteristic(
      TIME_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY);

  tempChar->addDescriptor(new BLE2902());
  humChar->addDescriptor(new BLE2902());
  timeChar->addDescriptor(new BLE2902());

  service->start();

  BLEAdvertising *advertising = BLEDevice::getAdvertising();
  advertising->addServiceUUID(SERVICE_UUID);
  advertising->start();

  Serial.println("BLE Sensor Started");
}

void loop() {

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (!isnan(temp) && !isnan(hum)) {

    tempChar->setValue(String(temp).c_str());
    humChar->setValue(String(hum).c_str());
    timeChar->setValue(String(millis()).c_str());

    tempChar->notify();
    humChar->notify();
    timeChar->notify();

    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.print(" C  Humidity: ");
    Serial.print(hum);
    Serial.print("%  Time: ");
    Serial.println(millis());
  }

  delay(3000);
}
