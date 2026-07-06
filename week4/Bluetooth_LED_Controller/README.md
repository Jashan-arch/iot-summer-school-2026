# Bluetooth LED Controller

## Project Description

This project controls three LEDs (Red, Green, and Blue) using an HC-05 Bluetooth module and an Android phone.

## Hardware Required

- Arduino Uno
- HC-05 Bluetooth Module
- Red LED
- Green LED
- Blue LED
- 3 × 220 Ω Resistors
- Breadboard
- Jumper Wires

## Bluetooth Pairing Instructions

1. Power the Arduino and HC-05 module.
2. Enable Bluetooth on your Android phone.
3. Search for available Bluetooth devices.
4. Select **HC-05**.
5. Enter the pairing PIN:
   - **1234** (default), or
   - **0000** (if 1234 does not work).
6. Open a Bluetooth terminal app (for example, "Serial Bluetooth Terminal").
7. Connect to the HC-05 module.

## Commands

| Command | Action |
|---------|--------|
| R | Turn Red LED ON |
| G | Turn Green LED ON |
| B | Turn Blue LED ON |
| X | Turn All LEDs OFF |
| F | Flash All LEDs 5 Times |
