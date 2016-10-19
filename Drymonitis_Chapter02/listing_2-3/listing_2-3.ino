// set a global variable for the pin of the switch
int switch_pin = 2;
// set a global variable for the pin of the LED
int led_pin = 8;

void setup() {
  // initialize the switch pin as input with the internal pull-up resistor
  pinMode(switch_pin, INPUT_PULLUP);
  // initialize the LED pin as output
  pinMode(led_pin, OUTPUT);
  
  // start the serial communication so we can see the readings in our computer
  Serial.begin(9600);
}

void loop() {
  // store the state of the switch to a variable
  int switch_state = !digitalRead(switch_pin);

  // write the reading of the switch to the LED
  digitalWrite(led_pin, switch_state);

  // print the variable to the Serial Monitor
  Serial.println(switch_state);

  // short delay so that we don't receive massive data
  delay(250);
}
