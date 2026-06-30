/*
---------------------------------------------------------
Project : Ultrasonic Parking Sensor
Author  : Shubh Jashan Singh
---------------------------------------------------------
*/

const int trigPin = 9;
const int echoPin = 10;

const int greenLED = 2;
const int yellowLED = 3;
const int redLED = 4;

const int buzzer = 8;

unsigned long previousMillis = 0;
bool toggleState = false;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // Measure Distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  float distance = (duration * 0.034) / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  unsigned long currentMillis = millis();

  // Reset outputs
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  noTone(buzzer);

  //---------------- SAFE ----------------
  if (distance > 50) {

    digitalWrite(greenLED, HIGH);

    Serial.println("SAFE");
  }

  //---------------- WARNING ----------------
  else if (distance > 20 && distance <= 50) {

    digitalWrite(yellowLED, HIGH);

    if (currentMillis - previousMillis >= 500) {

      previousMillis = currentMillis;

      toggleState = !toggleState;

      if (toggleState)
        tone(buzzer, 1000);
      else
        noTone(buzzer);
    }

    Serial.println("WARNING");
  }

  //---------------- DANGER ----------------
  else if (distance > 10 && distance <= 20) {

    digitalWrite(redLED, HIGH);

    if (currentMillis - previousMillis >= 200) {

      previousMillis = currentMillis;

      toggleState = !toggleState;

      if (toggleState)
        tone(buzzer, 1000);
      else
        noTone(buzzer);
    }

    Serial.println("DANGER");
  }

  //---------------- STOP ----------------
  else {

    if (currentMillis - previousMillis >= 100) {

      previousMillis = currentMillis;

      toggleState = !toggleState;

      digitalWrite(greenLED, toggleState);
      digitalWrite(yellowLED, toggleState);
      digitalWrite(redLED, toggleState);
    }

    tone(buzzer, 1000);

    Serial.println("STOP");
  }
}
