#include <ADCTouch.h>

int ref0, ref1;     //reference values to remove offset
int led_state = 0;


void setup() 
{
    // No pins to setup, pins can still be used regularly, although it will affect readings

    Serial.begin(9600);

    ref0 = ADCTouch.read(A0, 10);    //create reference values to 
    ref1 = ADCTouch.read(A1, 10);    //account for the capacitance of the pad

    pinMode(13, OUTPUT);
} 

void loop() 
{
    int value0 = ADCTouch.read(A0);   //no second parameter
    int value1 = ADCTouch.read(A1);   //   --> 100 samples

    value0 -= ref0;       //remove offset
    value1 -= ref1;

    Serial.print(value0 > 40);    //send (boolean) pressed or not pressed
    Serial.print("\t");           //use if(value > threshold) to get the state of a button

    if (value0 > 40 == 1) {
      if (led_state == 0){
        digitalWrite(13, 1);
        led_state = 1;
        delay(200);
      }
      else {
        digitalWrite(13, 0);
        led_state = 0;
        delay(200);
      }
    }

    Serial.print(value0);
    Serial.print("\t\n");
    delay(5);
}
