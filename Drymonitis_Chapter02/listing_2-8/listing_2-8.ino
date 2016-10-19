// potentiometer array size, must be constant
const int num_of_pots = 3;
// push-button array size, must be constant
const int num_of_buttons = 3;

// create an array to store the values of the potentiometers
int pots[num_of_pots];
// create an array to store the values of the push-buttons
int buttons[num_of_buttons];

void setup() {
  for(int i = 0; i < num_of_buttons; i++){
    pinMode((i + 2), INPUT_PULLUP);
  }
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < num_of_pots; i++) pots[i] = analogRead(i);

  for(int i = 0; i < num_of_buttons; i++) buttons[i] = !digitalRead(i + 2);

  Serial.print("Pot_values: ");
  for(int i = 0; i < (num_of_pots - 1); i++){
    Serial.print(pots[i]);
    Serial.print(" ");
  }
  Serial.println(pots[num_of_pots - 1]);

  Serial.print("Button_values: ");
  for(int i = 0; i < (num_of_buttons - 1); i++){
    Serial.print(buttons[i]);
    Serial.print(" ");
  }
  Serial.println(buttons[num_of_buttons - 1]);
}

