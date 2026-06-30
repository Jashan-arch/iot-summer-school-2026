/*
-----------------------------------------------------
Smart Street Light
Author: Shubh Jashan Singh
-----------------------------------------------------
*/

const int ldrPin = A0;
const int pirPin = 2;
const int ledPin = 9;

const int threshold = 500;

unsigned long lastMotionTime = 0;
bool motionDetected = false;

void printEvent(String event);

void setup() {

  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int lightValue = analogRead(ldrPin);

  // -------- DAY --------
  if (lightValue > threshold) {

    analogWrite(ledPin, 0);

    printEvent("DAYLIGHT - LED OFF");

    delay(1000);
    return;
  }

  // -------- NIGHT --------
  printEvent("Night Mode");

  if (digitalRead(pirPin) == HIGH) {

    motionDetected = true;
    lastMotionTime = millis();

    analogWrite(ledPin, 255);

    printEvent("Motion Detected - LED FULL");
  }

  if (motionDetected) {

    if (millis() - lastMotionTime >= 30000) {

      motionDetected = false;

      analogWrite(ledPin, 51);

      printEvent("No Motion - LED DIM (20%)");
    }

  } else {

    analogWrite(ledPin, 51);
  }

  delay(100);
}

//---------------------------------------
void printEvent(String event) {

  unsigned long sec = millis() / 1000;

  int h = sec / 3600;
  int m = (sec % 3600) / 60;
  int s = sec % 60;

  Serial.print("[");

  if (h < 10) Serial.print("0");
  Serial.print(h);
  Serial.print(":");

  if (m < 10) Serial.print("0");
  Serial.print(m);
  Serial.print(":");

  if (s < 10) Serial.print("0");
  Serial.print(s);

  Serial.print("] EVENT: ");

  Serial.println(event);
}
