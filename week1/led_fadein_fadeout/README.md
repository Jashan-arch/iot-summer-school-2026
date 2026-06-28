# LED Fade Sequence Using PWM

## Project Title

LED Fade Sequence Using PWM on Arduino

---

## Project Overview

This project demonstrates Pulse Width Modulation (PWM) on an Arduino Uno by gradually fading six LEDs in and out one after another. The LEDs are connected to PWM-enabled digital pins, and the brightness is controlled using the `analogWrite()` function. This project helps understand PWM, loops, arrays, and LED brightness control in Arduino programming.

---

## Hardware Required

* Arduino Uno (or compatible Arduino board)
* 6 × LEDs
* 6 × 220 Ω resistors
* Breadboard
* Jumper wires
* USB cable
* Computer with Arduino IDE

---

## Circuit Diagram Description (Text-Based)

Connect each LED to a PWM-capable digital pin through a 220 Ω resistor.

| Arduino Pin | Component                        |
| ----------- | -------------------------------- |
| Pin 3       | LED 1 (+) through 220 Ω resistor |
| Pin 5       | LED 2 (+) through 220 Ω resistor |
| Pin 6       | LED 3 (+) through 220 Ω resistor |
| Pin 9       | LED 4 (+) through 220 Ω resistor |
| Pin 10      | LED 5 (+) through 220 Ω resistor |
| Pin 11      | LED 6 (+) through 220 Ω resistor |

* Connect the cathode (-) of all LEDs to the Arduino GND.
* Connect the Arduino to the computer using a USB cable.

---

## How to Upload the Code

1. Connect the Arduino Uno to your computer using a USB cable.
2. Open the Arduino IDE.
3. Open the `led_blink.ino` sketch.
4. Select **Tools → Board → Arduino Uno**.
5. Select the correct COM port from **Tools → Port**.
6. Click **Verify (✓)** to compile the code.
7. Click **Upload (→)** to upload the program to the Arduino.
8. Wait until the IDE displays **Done Uploading**.

---

## Expected Output

* The first LED gradually fades from OFF to full brightness and then fades back to OFF.
* After the first LED finishes, the second LED performs the same fading effect.
* The sequence continues through all six LEDs.
* Once the sixth LED finishes, the sequence repeats continuously.

---

## Troubleshooting Tips

1. Ensure all LEDs are connected to the correct PWM pins (3, 5, 6, 9, 10, and 11).
2. Check that each LED has a 220 Ω resistor connected in series to prevent damage.
3. Verify that the correct Arduino board and COM port are selected in the Arduino IDE.
4. If an LED does not light, check its polarity (long leg to the Arduino pin through the resistor, short leg to GND).
5. If the code does not upload, reconnect the USB cable and close any application using the serial port.

---

## Files

* `led_blink.ino` – Arduino source code for the LED fading sequence.
* `README.md` – Project documentation.

---

## Author

**Name:** Your Name

**Roll Number:** Your Roll Number
