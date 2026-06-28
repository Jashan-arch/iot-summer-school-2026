/*
Author: Shubh jashan Singh
Date: 28-06-2026
Description:
LED blink program with serial monitoring and potentiometer-controlled blink speed.
*/

int blinkCount = 0;
int potPin = A0;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int delayTime = analogRead(potPin);
  delayTime = map(delayTime, 0, 1023, 100, 1000);

  digitalWrite(13, HIGH);
  delay(delayTime);

  digitalWrite(13, LOW);
  delay(delayTime);

  blinkCount++;

  Serial.print("Blink count: ");
  Serial.println(blinkCount);
}
