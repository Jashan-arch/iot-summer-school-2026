/*
Author: Shubh jashan Singh
Date: 28-06-2026
Description:
LED blink program with serial monitoring and potentiometer-controlled blink speed.
*/

// Variable to store the number of LED blinks
int blinkCount = 0;

// Analog pin where the potentiometer is connected
int potPin = A0;

void setup() {

  // Configure Digital Pin 13 as an output for the LED
  pinMode(13, OUTPUT);

  // Start serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {

  // Read the analog value from the potentiometer (0 - 1023)
  int potValue = analogRead(potPin);

  // Convert the potentiometer reading into a delay value
  // Delay ranges from 100 ms to 1000 ms
  int delayTime = map(potValue, 0, 1023, 100, 1000);

  // Turn the LED ON
  digitalWrite(13, HIGH);

  // Keep the LED ON for the calculated delay
  delay(delayTime);

  // Turn the LED OFF
  digitalWrite(13, LOW);

  // Keep the LED OFF for the same delay
  delay(delayTime);

  // Increase the blink counter after one complete blink
  blinkCount++;

  // Display the blink count on the Serial Monitor
  Serial.print("Blink count: ");
  Serial.println(blinkCount);

  // Display the current delay value
  Serial.print("Current Delay: ");
  Serial.print(delayTime);
  Serial.println(" ms");

  // Print a blank line for better readability
  Serial.println();
}
