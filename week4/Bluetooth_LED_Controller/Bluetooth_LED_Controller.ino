/*
-------------------------------------------------------
Project: Bluetooth LED Controller (HC-05 + Arduino)
Author: Shubh Jashan Singh
Date: 30-06-2026
-------------------------------------------------------
*/

#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11);   // RX, TX

const int redLED = 3;
const int greenLED = 5;
const int blueLED = 6;

void setup() {

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(blueLED, LOW);

  Serial.begin(9600);
  BT.begin(9600);

  Serial.println("Bluetooth LED Controller Ready");
}

void loop() {

  if (BT.available()) {

    char cmd = BT.read();

    Serial.print("Received: ");
    Serial.println(cmd);

    switch (cmd) {

      case 'R':
        digitalWrite(redLED, HIGH);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, LOW);
        break;

      case 'G':
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, HIGH);
        digitalWrite(blueLED, LOW);
        break;

      case 'B':
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, HIGH);
        break;

      case 'X':
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, LOW);
        break;

      case 'F':

        for (int i = 0; i < 5; i++) {

          digitalWrite(redLED, HIGH);
          digitalWrite(greenLED, HIGH);
          digitalWrite(blueLED, HIGH);
          delay(300);

          digitalWrite(redLED, LOW);
          digitalWrite(greenLED, LOW);
          digitalWrite(blueLED, LOW);
          delay(300);
        }

        break;

      default:
        Serial.println("Unknown Command");
        break;
    }
  }
}
