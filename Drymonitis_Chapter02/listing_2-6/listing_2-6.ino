// create an array to store the values of the potentiometers
int pots[3];

void setup() {
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < 3; i++){
    pots[i] = analogRead(i);
  }

  Serial.print("Pot values: ");
  Serial.print(pots[0]);
  Serial.print(" ");
  Serial.print(pots[1]);
  Serial.print(" ");
  Serial.println(pots[2]);

  delay(500);
}

