| **Feature**      | **analogRead()**                       | **analogWrite()**                                 |
| ---------------- | -------------------------------------- | ------------------------------------------------- |
| **Purpose**      | Reads an analog voltage from a sensor. | Generates a PWM signal to simulate analog output. |
| **Pins Used**    | Analog input pins (A0–A5).             | PWM pins (3, 5, 6, 9, 10, 11).                    |
| **Input/Output** | Input                                  | Output                                            |
| **Value Range**  | 0–1023 (10-bit ADC)                    | 0–255 (8-bit PWM)                                 |
| **Example**      | Reading a temperature or light sensor. | Controlling LED brightness or motor speed.        |

PWM (Pulse Width Modulation) is a technique used to simulate an analog output by rapidly switching a digital pin ON and OFF.
By changing the percentage of time the signal stays ON, Arduino can control the average voltage delivered to a device.

A PWM is used to control led brightness and DC Motor speed.

Practical IoT Examples

1. analogRead() Example:

Project: Smart Plant Watering System
A soil moisture sensor connected to pin A0 sends an analog value to the Arduino using analogRead().
If the soil is dry, the Arduino turns on a water pump automatically.

2. analogWrite() Example:

Project: Smart Street Lighting
An LED street light connected to a PWM pin changes its brightness using analogWrite().
At night, the brightness increases, while during dawn or dusk it is reduced to save energy.
