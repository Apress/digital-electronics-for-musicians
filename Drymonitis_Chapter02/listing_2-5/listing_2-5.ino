int pot_pin = 0;
int led_pin = 9;

void setup() {
  pinMode(led_pin, OUTPUT);
}

void loop() {
  int pot_val = analogRead(pot_pin);

  // map the readings of the potentiometer to the range of PWM
  pot_val = map(pot_val, 0, 1023, 0, 255);

  // write the mapped value to the PWM pin of the LED
  analogWrite(led_pin, pot_val);

  delay(250);
}
