# LED Blink Project

## Project Title

**LED Blink with Serial Monitor and Potentiometer Speed Control**

---

## Project Overview

This Arduino project demonstrates how to blink an LED connected to pin 13. The program also displays the blink count on the Serial Monitor and allows the blink speed to be adjusted using a potentiometer connected to analog pin A0. This project introduces basic digital output, analog input, and serial communication concepts.

---

## Hardware Required

* Arduino Uno (or compatible board)
* USB cable
* 1 × LED
* 1 × 220 Ω resistor
* 1 × 10 kΩ potentiometer
* Breadboard
* Jumper wires

---

## Circuit Diagram Description

1. Connect the LED anode (+) to Digital Pin 13 through a 220 Ω resistor.
2. Connect the LED cathode (−) to the Arduino GND pin.
3. Connect one outer pin of the potentiometer to 5V.
4. Connect the other outer pin of the potentiometer to GND.
5. Connect the middle (wiper) pin of the potentiometer to Analog Pin A0.
6. Connect the Arduino to the computer using a USB cable.

---

## How to Upload the Code

1. Connect the Arduino board to your computer using a USB cable.
2. Open the Arduino IDE.
3. Open the `led_blink.ino` sketch.
4. Select **Tools → Board → Arduino Uno** (or your board model).
5. Select the correct COM port from **Tools → Port**.
6. Click the **Verify (✓)** button to compile the program.
7. Click the **Upload (→)** button.
8. After uploading, open the **Serial Monitor** and set the baud rate to **9600**.

---

## Expected Output

* The LED connected to Pin 13 blinks continuously.
* The blink speed changes as the potentiometer is rotated.
* The Serial Monitor displays:

```
Blink count: 1
Blink count: 2
Blink count: 3
...
```

* The LED continues blinking until the board is powered off or reset.

---

## Troubleshooting Tips

1. Ensure the correct Arduino board and COM port are selected before uploading.
2. If the LED does not blink, check the wiring and resistor connections.
3. Verify that the potentiometer's center pin is connected to Analog Pin A0.
4. If no data appears in the Serial Monitor, make sure the baud rate is set to **9600**.
5. If the upload fails, disconnect and reconnect the USB cable, then try uploading again.

---

## Author

**Name:** Shubh Jashan Singh
