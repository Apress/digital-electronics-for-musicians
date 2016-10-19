const int num_of_leds = 3;

int led_pins[num_of_leds] = { 3, 5, 6};

void setup() {
  for(int i = 0; i < num_of_leds; i++) pinMode(led_pins[i], OUTPUT);

  Serial.begin(57600);
}

void loop() {
  if(Serial.available()){
    static int temp_val;
    byte in_byte = Serial.read();
    if((in_byte >= '0') && (in_byte <= '9'))
      temp_val = temp_val * 10 + in_byte - '0';
    else if((in_byte >= 'a') && (in_byte <= 'z')){
      int which_pin = in_byte - 'a';
      analogWrite(led_pins[which_pin], temp_val);
      temp_val = 0;
    }
  }
}
