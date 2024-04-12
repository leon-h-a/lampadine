#include <ADCTouch.h>

int ref;
int led_state = 0;
int brightness = 0;
int init_flag = 0;
int up_flag = 0;
int down_flag = 0;

int rampDelay = 4;
int holdCheckTimeout = 100;
int toggleThr = 250;


void setup() 
{
    pinMode(1, OUTPUT);
    ref = ADCTouch.read(A3, 500);    // sense pin uC#3
}

int rampUp(){  // Return True if ramp exited and False if rampDown should be called
  int hold = ADCTouch.read(A3);
  hold -= ref;

  // Here will be edge cases when user touched but this
  // func was called. Test gracefull exit by mimicking
  // user touch.
  if (hold < toggleThr){
    led_state = 1;
    return 1;
  }

  up_flag = 1;
  down_flag = 0;

  if (brightness > 240){
    // End of ramp, call rampDown in main
    led_state = 1;
    return 0;
  }
  else {
    brightness += 5;
    analogWrite(1, brightness);
    }
  delay(rampDelay);
};

int rampDown(){  // Return True if ramp exited and False if rampUp should be called
  while (1){
    int hold = ADCTouch.read(A3);
    hold -= ref;

    if (hold < toggleThr){
      led_state = 1;
      return 1;
    }

    up_flag = 0;
    down_flag = 1;

    if (brightness < 10) {
      // End of ramp, call rampUp from main
      led_state = 0;
      return 0;
    }
    else {
      brightness -= 5;
      analogWrite(1, brightness);
    }
    delay(rampDelay); 
  }
};

void loop() 
{
    int touch = ADCTouch.read(A3);
    touch -= ref;

    // User pressed sens
    if (touch > toggleThr) {  // Raw ADC value
      
      // Turn on lamp to full power only on first sens-ON after HW reset
      if (init_flag == 0){
        init_flag = 1;
        analogWrite(1, 255);
        led_state = 1;
        brightness = 255;
      }

      else {
        // Define delay as something that is not visible
        // But enough to differentiate between touch/hold
        delay(holdCheckTimeout);
  
        int hold = ADCTouch.read(A3);
        hold -= ref;
  
        if (hold > toggleThr) {  // Raw ADC value
          // Cap sens active after delay -> User hold
          if (brightness > 125){
            int status = rampDown();
          }
          else {
           int status = rampUp(); 
          }
        }
  
        else {
          // Cap sense not active -> User touch
          if (led_state == 0){
            analogWrite(1, brightness);
            led_state = 1;
          }
          else {
            analogWrite(1, 0);
            led_state = 0;
          }
        }
      }
    }
    
    delay(5);
}
