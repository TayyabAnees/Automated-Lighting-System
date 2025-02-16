# Automated Lighting System

An automated lighting system that adjusts brightness based on room occupancy and ambient light levels. The system uses a PIR motion sensor to detect movement and turns on the lights only if the room is dark. A light-dependent resistor (LDR) continuously measures ambient light to adjust the LED brightness. If no motion is detected for 5 minutes, the lights turn off to save energy. A manual override switch allows users to turn off the system completely.

## Features
- **Motion Detection:** Lights turn on when motion is detected and it's dark.
- **Ambient Light Adjustment:** LED brightness adjusts dynamically based on ambient light levels.
- **Energy Saving:** Lights turn off after 5 minutes of no motion.
- **Manual Override:** A master switch allows users to disable the system.

## Design
![Circuit Diagram](https://github.com/TayyabAnees/Automated-Lighting-System/blob/master/images/SchematicView.png)

## Schematic View
![Schematic View](https://github.com/TayyabAnees/Automated-Lighting-System/blob/master/images/deisgn.png))

## Demo


## Component List

| Name     | Quantity | Component         |
|----------|---------|------------------|
| Uprocessor | 1     | Arduino Uno R3   |
| RLDR     | 1       | Photoresistor    |
| Dled     | 1       | Red LED          |
| S1       | 1       | Slide Switch     |
| PIR1     | 1       | PIR Sensor       |
| R1       | 1       | 100 Ω Resistor   |
| R2       | 1       | 1000 Ω Resistor  |

## How It Works
1. The PIR sensor detects motion and sends a signal to the Arduino.
2. The LDR continuously measures ambient light levels.
3. If motion is detected and the room is dark, the LED turns on.
4. The brightness of the LED adjusts based on the LDR reading.
5. If no motion is detected for 5 minutes, the LED turns off.
6. The manual override switch allows users to disable the system.

## Code
The Arduino code for this system can be found in the `automated_lighting.ino` file in this repository.

## License
This project is open-source and available under the MIT License.

