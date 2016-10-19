int analog_pin = 0;
 
void setup() {
  // begin the serial communication
  Serial.begin(9600);
}
 
void loop() {
  // store value of potentiometer to a variable
  int pot_val = analogRead(analog_pin);
 
  // print it to the Serial Monitor
  Serial.println(pot_val);
 
  // short delay to avoid massive data
  delay(250);
}
