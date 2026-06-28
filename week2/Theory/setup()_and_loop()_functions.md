**setup()**
The setup() function runs only once when the Arduino is powered on or reset.
It is used to initialize pins, sensors, serial communication, and other hardware.

**loop()**
The loop() function runs continuously after setup() finishes.
It contains the main program logic, such as reading sensors and controlling devices.

loop()
The loop() function runs continuously after setup() finishes.
It contains the main program logic, such as reading sensors and controlling devices.

It affects the responsiveness of sensor by:
Sensor readings become slow.
Button presses or motion detection may be missed during the delay.
Real-time IoT applications become less responsive.
The system cannot perform multiple tasks efficiently.

The non-blocking alternative is to use the millis() function.

millis() returns the number of milliseconds since the Arduino started.
It allows the Arduino to keep checking sensors while performing other tasks, without stopping the program.
