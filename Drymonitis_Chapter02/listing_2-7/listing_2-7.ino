// potentiometer array size, must be constant
const int num_of_analog_pins = 3;
// push-button array size, must be constant
const int num_of_digital_pins = 3;

// create an array to store the values of the potentiometers
int analog_values[num_of_analog_pins];
// create an array to store the values of the push-buttons
int digital_values[num_of_digital_pins];

void setup() {
  for(int i = 0; i < num_of_digital_pins; i++){
    pinMode((i + 2), INPUT_PULLUP);
  }
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < num_of_analog_pins; i++){
    analog_values[i] = analogRead(i);
  }

  for(int i = 0; i < num_of_digital_pins; i++){
    digital_values[i] = !digitalRead(i + 2);
  }

  Serial.print("Analog values: ");
  for(int i = 0; i < num_of_analog_pins; i++){
    Serial.print(analog_values[i]);
    Serial.print(" ");
  }

  Serial.print("Digital values: ");
  for(int i = 0; i < (num_of_digital_pins - 1); i++){
    Serial.print(digital_values[i]);
    Serial.print(" ");
  }
  Serial.println(digital_values[num_of_digital_pins - 1]);

  delay(500);
}

