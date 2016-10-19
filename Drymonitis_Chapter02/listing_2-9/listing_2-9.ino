// potentiometer array size, must be constant
const int num_of_pots = 3;
// push-button array size, must be constant
const int num_of_buttons = 3;

// assemble number of bytes we need
// analog values are being split in two, so their number times 2
// and we need a unique byte to denote the beginning of the data stream
const int num_of_bytes = (num_of_pots * 2) + num_of_buttons + 1;

// array to store all bytes
byte transfer_array[num_of_bytes];

void setup() {
  for(int i = 0; i < num_of_buttons; i++) pinMode((i + 2), INPUT_PULLUP);
  
  Serial.begin(57600);
}

void loop() {
  transfer_array[0] = 0xc0; // denote beginning of data
  int index = 1; // index offset
  
  // store the analog values to the array
  for(int i = 0; i < num_of_pots; i++){
    int pot_val = analogRead(i);
    transfer_array[index++] = pot_val & 0x007f;
    transfer_array[index++] = pot_val >> 7;
  }

  // store the digital values to the array
  for(int i = 0; i < num_of_buttons; i++) transfer_array[index++] = !digitalRead(i + 2);

  // transfer bytes over serial
  Serial.write(transfer_array, num_of_bytes);
}
