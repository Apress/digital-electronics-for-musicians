int led_pin = 13;

void setup() {
  pinMode(13, OUTPUT);

  Serial.begin(57600);
}

void loop() {
  if(Serial.available()){
    byte in_byte = Serial.read();
    digitalWrite(led_pin, in_byte);
  }
}
