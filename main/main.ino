int analog_out = 0;
int up_flag = 1;
int down_flag = 0;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(0, OUTPUT);
}

void loop() {

  analogWrite(0, analog_out);

  if (analog_out >= 250) {
    up_flag = 0;
    down_flag = 1;
  }
  if (analog_out <= 10) {
    up_flag = 1;
    down_flag = 0;
  }

  if (up_flag == 1) {
    analog_out += 10;
  }
  else {
    analog_out -= 10;
  }
  
  delay(50);
}
