/*
------------------------------------------------------
Project: Servo Motor Sweep
Author: Shubh Jashan Singh
Date: 28-06-2026
------------------------------------------------------
*/

#include <Servo.h>

Servo servo;

const int servoPin = 9;
const int potPin = A0;
const int buttonPin = 2;

void setup() {

  Serial.begin(9600);

  servo.attach(servoPin);

  pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {

  // Button pressed?
  if (digitalRead(buttonPin) == LOW) {

    // Sweep 0 -> 180
    for(int angle=0; angle<=180; angle++){
      servo.write(angle);
      delay(10);
    }

    // Sweep 180 -> 0
    for(int angle=180; angle>=0; angle--){
      servo.write(angle);
      delay(10);
    }

    delay(300);
  }

  // Potentiometer Control
  int value = analogRead(A0);

  int angle = map(value,0,1023,0,180);

  servo.write(angle);

  Serial.print("Servo Angle: ");
  Serial.println(angle);

  delay(100);

}
