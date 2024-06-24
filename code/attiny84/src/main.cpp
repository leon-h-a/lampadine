#include <ADCTouch.h>
// #include <SoftwareSerial.h>

// Serial comms
// #define rxPin 3
// #define txPin 4
// SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);

// LEDS
int ledPin = 1;

void setup() {
    // Define pin modes for TX and RX
    // pinMode(rxPin, INPUT);
    // pinMode(txPin, OUTPUT);
    // Set the baud rate for the SoftwareSerial object
    // mySerial.begin(9600);

    // LEDS
    pinMode(ledPin, OUTPUT);  // sets the pin as output
}


void loop() {
    analogWrite(ledPin, 255);
    delay(50);

    analogWrite(ledPin, 0);
    delay(50);

    // mySerial.println(22);
    // delay(500);
}
