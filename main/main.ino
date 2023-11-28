#include <ADCTouch.h>

int ref0, ref1;     //reference values to remove offset
int led_state = 0;


void setup() 
{
    // No pins to setup, pins can still be used regularly, although it will affect readings

    // Serial.begin(9600);
    pinMode(1, OUTPUT);

    ref0 = ADCTouch.read(A3, 500);    // sense pin uC#2 
} 

void loop() 
{
    int value0 = ADCTouch.read(A3);

    value0 -= ref0;       //remove offset

    if (value0 > 100) {
      if (led_state == 0){
        digitalWrite(1, 1);
        led_state = 1;
        delay(200);
      }
      else {
        digitalWrite(1, 0);
        led_state = 0;
        delay(200);
      }
    }
    delay(5);
}
