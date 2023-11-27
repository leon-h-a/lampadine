### Connection diagram for porgrammer
ARD_10 -> uC[1]
ARD_11 -> uC[5]
ARD_12 -> uC[6]
ARD_13 -> uC[7]
VCC -> VCC
GND -> GND

### Settings for programming via Arduino
1. Burn ArduinoISP
2. Add attiny lib: https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json & install it
3. Board: Attiny85, Programmer: Arduino as ISP
4. Flash
