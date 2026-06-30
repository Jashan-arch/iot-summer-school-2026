/*
-------------------------------------------------------
Project: DC Motor Speed Control
Author: Swarnava Dey
Date: 30-06-2026
-------------------------------------------------------
*/

const int ENA = 9;
const int IN1 = 8;
const int IN2 = 7;

const int potPin = A0;
const int dirButton = 2;
const int startButton = 3;

bool direction = true;      // true = Forward
bool motorRunning = true;

bool lastDirState = HIGH;
bool lastStartState = HIGH;

void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(dirButton, INPUT_PULLUP);
  pinMode(startButton, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  // -------- Direction Button --------
  bool dirState = digitalRead(dirButton);

  if (lastDirState == HIGH && dirState == LOW) {
    direction = !direction;
    delay(200);
  }

  lastDirState = dirState;

  // -------- Start/Stop Button --------
  bool startState = digitalRead(startButton);

  if (lastStartState == HIGH && startState == LOW) {
    motorRunning = !motorRunning;
    delay(200);
  }

  lastStartState = startState;

  // -------- Read Potentiometer --------
  int potValue = analogRead(potPin);

  int pwm = map(potValue, 0, 1023, 0, 255);
  int speedPercent = map(pwm, 0, 255, 0, 100);

  if (motorRunning) {

    analogWrite(ENA, pwm);

    if (direction) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
    }
    else {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
    }

  } else {

    analogWrite(ENA, 0);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }

  // -------- Serial Output --------
  Serial.print("Direction: ");

  if (direction)
    Serial.print("Forward");
  else
    Serial.print("Reverse");

  Serial.print(" | Speed: ");
  Serial.print(speedPercent);
  Serial.print("%");

  Serial.print(" | State: ");

  if (motorRunning)
    Serial.println("Running");
  else
    Serial.println("Stopped");

  delay(500);
}
