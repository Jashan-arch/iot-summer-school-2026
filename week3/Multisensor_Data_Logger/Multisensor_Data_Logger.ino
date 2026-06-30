/*
----------------------------------------------------
Project: Multi-Sensor Data Logger
Author: Shubh Jashan Singh
Date: 30-06-2026
==================
*/

#include <DHT.h>

// -------- DHT11 --------
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// -------- LDR --------
const int ldrPin = A0;

// -------- HC-SR04 --------
const int trigPin = 9;
const int echoPin = 10;

unsigned long previousMillis = 0;
const unsigned long interval = 5000;

void setup() {

  Serial.begin(9600);

  dht.begin();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.println("Environmental Monitoring Started");
}

void loop() {

  if (millis() - previousMillis >= interval) {

    previousMillis = millis();

    //-------------------------
    // Read DHT11
    //-------------------------

    float humidity = dht.readHumidity();
    float tempC = dht.readTemperature();

    if (isnan(humidity) || isnan(tempC)) {
      Serial.println("Failed to read DHT11!");
      return;
    }

    //-------------------------
    // Read LDR
    //-------------------------

    int ldrValue = analogRead(ldrPin);

    int lightPercent = map(ldrValue, 0, 1023, 0, 100);

    String lightCondition;

    if (lightPercent >= 70)
      lightCondition = "Bright";
    else if (lightPercent >= 40)
      lightCondition = "Normal";
    else
      lightCondition = "Dark";

    //-------------------------
    // Read HC-SR04
    //-------------------------

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);

    float distance = duration * 0.034 / 2.0;

    //-------------------------
    // Print Output
    //-------------------------

    Serial.println("==================");
    Serial.println("SENSOR LOG");

    Serial.print("Time      : ");
    Serial.print(millis());
    Serial.println(" ms");

    Serial.print("Temp      : ");
    Serial.print(tempC, 1);
    Serial.print(" C | Humidity: ");
    Serial.print(humidity, 1);
    Serial.println("%");

    Serial.print("Light     : ");
    Serial.print(lightPercent);
    Serial.print("% (");
    Serial.print(lightCondition);
    Serial.println(")");

    Serial.print("Distance  : ");
    Serial.print(distance, 1);
    Serial.println(" cm");

    Serial.println("==================");
    Serial.println();
  }
}
