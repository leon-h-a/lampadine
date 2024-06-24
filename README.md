### Connection between Arduino and PCB header
    ARD_13  -> 1
    ARD_12  -> 2
    ARD_11  -> 3
    ARD_10  -> 4
    ARD_GND -> 5

### Settings for programming via Arduino (platformio)
1. Install platformio on Windows
2. Init project ```pio project init --board attiny85``` ($ pio boards)
3. Install dependency ```pio lib install ADCTouch```
4. Setup Platformio to flash via Arduino (platformio.ini)

        [env:attiny85]
        platform = atmelavr
        board = attiny85
        framework = arduino
        upload_protocol = stk500v1
        lib_deps = martin2250/ADCTouch@^1.0.4
        upload_flags =
                -P$UPLOAD_PORT
                -b$UPLOAD_SPEED
        upload_port = COM7
        upload_speed = 19200

5. Flash with ```pio run --target upload```

### In case of avrdude verification error, mismatch byte

Remember to power PCB via USB-C before uploading.

### Timing issues

Define 'board_build.f_cpu' flag in platformio.ini conf file
