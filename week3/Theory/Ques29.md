# Sensor Calibration

## What is sensor calibration and why is it important?
**Sensor calibration** is the process of comparing a sensor's raw output against known reference values and adjusting the readings (mathematically or in code) so they accurately reflect the real-world quantity being measured.

It's important in IoT systems because:
- Raw sensor values (e.g. 0–1023 from an ADC) don't directly correspond to meaningful units (%, °C, etc.) — they need to be mapped.
- Sensors vary slightly between units, age, and environment, so an uncalibrated sensor can give **misleading data**, leading to wrong automated decisions (e.g. an irrigation system watering when soil is already wet).
- Calibration ensures readings are **accurate, consistent, and comparable** across devices and over time.

## Calibrating an analog soil moisture sensor for percentage readings
A soil moisture sensor outputs a raw analog value (0–1023) based on conductivity between its probes. This raw value needs to be converted to a 0–100% scale that's meaningful to a user. To do this, you need two reference points:

1. **Dry reading:** Insert the sensor in completely dry soil (or air) and record the raw ADC value → this represents **0% moisture**.
2. **Wet reading:** Insert the sensor in fully water-saturated soil (or a cup of water) and record the raw ADC value → this represents **100% moisture**.

Then map any future reading between these two reference points using Arduino's `map()` function:

```cpp
int rawValue = analogRead(A0);
int dryValue = 520;   // raw value recorded in dry soil
int wetValue = 260;   // raw value recorded in saturated soil

int moisturePercent = map(rawValue, dryValue, wetValue, 0, 100);
moisturePercent = constrain(moisturePercent, 0, 100); // clamp to valid range
```

## The two-point calibration method
Two-point calibration uses exactly **two known reference values** (here, dry and wet) to define a **linear relationship** between the sensor's raw output and the real-world value:

1. Measure raw sensor output at reference point 1 (known low value, e.g. 0%).
2. Measure raw sensor output at reference point 2 (known high value, e.g. 100%).
3. Use linear interpolation (a straight line between these two points) to convert any raw reading in between into the corresponding real-world percentage.

This works well because the relationship between raw ADC value and moisture is approximately linear over the sensor's working range — two points are enough to define that line accurately, without needing complex multi-point curve fitting.
