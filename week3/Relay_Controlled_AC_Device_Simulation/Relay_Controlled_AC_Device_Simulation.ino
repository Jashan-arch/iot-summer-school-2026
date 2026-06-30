/*
-------------------------------------------------------
Project: Relay-Controlled AC Device Simulation
Author: Shbuh Jashan Singh
Date: 30-06-2026
-------------------------------------------------------
*/

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

const int relayPin = 8;      // LED or Relay
const int buttonPin = 3;

bool relayState = false;
bool lastButtonState = HIGH;

void setup() {

  Serial.begin(9600);

  dht.begin();

  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  digitalWrite(relayPin, LOW);

  Serial.println("Relay Controlled AC Simulation Started");
}

void loop() {

  float temp = dht.readTemperature();

  if (isnan(temp)) {
    Serial.println("DHT11 Read Error");
    delay(1000);
    return;
  }

  // -------- Automatic Control --------
  if (!relayState && temp > 32.0) {

    relayState = true;
    digitalWrite(relayPin, HIGH);

    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println(" °C | Relay ON (AC ON)");
  }

  else if (relayState && temp < 28.0) {

    relayState = false;
    digitalWrite(relayPin, LOW);

    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println(" °C | Relay OFF (AC OFF)");
  }

  // -------- Manual Override --------
  bool currentButton = digitalRead(buttonPin);

  if (lastButtonState == HIGH && currentButton == LOW) {

    relayState = !relayState;

    digitalWrite(relayPin, relayState);

    Serial.print("Temperature: ");
    Serial.print(temp);

    if (relayState)
      Serial.println(" °C | Manual Override -> Relay ON");
    else
      Serial.println(" °C | Manual Override -> Relay OFF");

    delay(250);   // Debounce
  }

  lastButtonState = currentButton;

  delay(1000);
}
