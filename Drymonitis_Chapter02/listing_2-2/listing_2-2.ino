// set a global variable for the pin of the switch
int switch_pin = 2;

void setup() {
  // initialize the switch pin as input
  pinMode(switch_pin, INPUT);
  
  // start the serial communication so we can see the readings in our computer
  Serial.begin(9600);
}

void loop() {
  // store the state of the switch to a variable
  int switch_state = digitalRead(switch_pin);

  // print the variable to the Serial Monitor
  Serial.println(switch_state);

  // short delay so that we don't receive massive data
  delay(250);
}
