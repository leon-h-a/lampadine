#include <ADCTouch.h>

int ref;
int ledPin = 1;
int toggleThr = 250;

void setup() {
    ref = ADCTouch.read(A2, 500);    // sense pin uC#3
    pinMode(ledPin, OUTPUT);  // sets the pin as output
}


void loop() {
    int hold = ADCTouch.read(A2);
    hold -= ref;

    if (hold > toggleThr) {
        analogWrite(ledPin, 255); 
    }
    else {
        analogWrite(ledPin, 0); 
    }
}
