const int inputPin1 = 2;
const int inputPin2 = 3;
const int inputPin3 = 4;
const int inputPin4 = 5;
const int inputPin5 = 6;

// State enumeration
enum State {
  STATE_UNKNOWN,
  STATE_ALL_LOW,
  STATE_INPUT_1_HIGH,
  STATE_INPUT_2_HIGH,
  STATE_INPUT_2_1_HIGH,
  STATE_INPUT_3_HIGH,
  STATE_INPUT_3_1_HIGH,
  STATE_INPUT_3_2_HIGH,
  STATE_INPUT_3_2_1_HIGH,
  STATE_INPUT_4_HIGH,
  STATE_INPUT_4_1_HIGH,
  STATE_INPUT_4_2_HIGH,
  STATE_INPUT_4_2_1_HIGH,
  STATE_INPUT_4_3_HIGH,
  STATE_INPUT_4_3_1_HIGH,
  STATE_INPUT_4_3_2_HIGH,
  STATE_INPUT_4_3_2_1_HIGH,
  STATE_INPUT_5_HIGH,
  STATE_INPUT_5_1_HIGH,
  STATE_INPUT_5_2_HIGH,
  STATE_INPUT_5_2_1_HIGH,
  STATE_INPUT_5_3_HIGH,
  STATE_INPUT_5_3_1_HIGH,
  STATE_INPUT_5_3_2_HIGH,
  STATE_INPUT_5_3_2_1_HIGH,
  STATE_INPUT_5_4_HIGH,
  STATE_INPUT_5_4_1_HIGH,
  STATE_INPUT_5_4_2_HIGH,
  STATE_INPUT_5_4_2_1_HIGH,
  STATE_INPUT_5_4_3_HIGH,
  STATE_INPUT_5_4_3_1_HIGH,
  STATE_INPUT_5_4_3_2_HIGH,
  STATE_ALL_HIGH
};

State currentState = STATE_UNKNOWN;
State previousState = STATE_UNKNOWN;

void setup() {
  Serial.begin(9600);

  pinMode(inputPin1, INPUT);
  pinMode(inputPin2, INPUT);
  pinMode(inputPin3, INPUT);
  pinMode(inputPin4, INPUT);
  pinMode(inputPin5, INPUT);
}

void loop() {
  // Read the state of each input pin
  int state1 = digitalRead(inputPin1);
  int state2 = digitalRead(inputPin2);
  int state3 = digitalRead(inputPin3);
  int state4 = digitalRead(inputPin4);
  int state5 = digitalRead(inputPin5);

  // Combine the states into a binary value
  int combination = state5 * 16 + state4 * 8 + state3 * 4 + state2 * 2 + state1;

  // Update the current state based on the combination
  switch (combination) {
    case 0b00000:
      currentState = STATE_ALL_LOW;
      break;
    case 0b00001:
      currentState = STATE_INPUT_1_HIGH;
      break;
    case 0b00010:
      currentState = STATE_INPUT_2_HIGH;
      break;
    case 0b00011:
      currentState = STATE_INPUT_2_1_HIGH;
      break;
    case 0b00100:
      currentState = STATE_INPUT_3_HIGH;
      break;
    case 0b00101:
      currentState = STATE_INPUT_3_1_HIGH;
      break;
    case 0b00110:
      currentState = STATE_INPUT_3_2_HIGH;
      break;
    case 0b00111:
      currentState = STATE_INPUT_3_2_1_HIGH;
      break;
    case 0b01000:
      currentState = STATE_INPUT_4_HIGH;
      break;
    case 0b01001:
      currentState = STATE_INPUT_4_1_HIGH;
      break;
    case 0b01010:
      currentState = STATE_INPUT_4_2_HIGH;
      break;
    case 0b01011:
      currentState = STATE_INPUT_4_2_1_HIGH;
      break;
    case 0b01100:
      currentState = STATE_INPUT_4_3_HIGH;
      break;
    case 0b01101:
      currentState = STATE_INPUT_4_3_1_HIGH;
      break;
    case 0b01110:
      currentState = STATE_INPUT_4_3_2_HIGH;
      break;
    case 0b01111:
      currentState = STATE_INPUT_4_3_2_1_HIGH;
      break;
    case 0b10000:
      currentState = STATE_INPUT_5_HIGH;
      break;
    case 0b10001:
      currentState = STATE_INPUT_5_1_HIGH;
      break;
    case 0b10010:
      currentState = STATE_INPUT_5_2_HIGH;
      break;
    case 0b10011:
      currentState = STATE_INPUT_5_2_1_HIGH;
      break;
    case 0b10100:
      currentState = STATE_INPUT_5_3_HIGH;
      break;
    case 0b10101:
      currentState = STATE_INPUT_5_3_1_HIGH;
      break;
    case 0b10110:
      currentState = STATE_INPUT_5_3_2_HIGH;
      break;
    case 0b10111:
      currentState = STATE_INPUT_5_3_2_1_HIGH;
      break;
    case 0b11000:
      currentState = STATE_INPUT_5_4_HIGH;
      break;
    case 0b11001:
      currentState = STATE_INPUT_5_4_1_HIGH;
      break;
    case 0b11010:
      currentState = STATE_INPUT_5_4_2_HIGH;
      break;
    case 0b11011:
      currentState = STATE_INPUT_5_4_2_1_HIGH;
      break;
    case 0b11100:
      currentState = STATE_INPUT_5_4_3_HIGH;
      break;
    case 0b11101:
      currentState = STATE_INPUT_5_4_3_1_HIGH;
      break;
    case 0b11110:
      currentState = STATE_INPUT_5_4_3_2_HIGH;
      break;
    case 0b11111:
      currentState = STATE_ALL_HIGH;
      break;
    default:
      currentState = STATE_UNKNOWN;
      break;
  }

  // Check if the current state has changed
  if (currentState != previousState) {
    // Print the current state
    printState(currentState);
    previousState = currentState;
  }

  delay(500);  // Delay between readings
}

// Function to print the state to the Serial monitor
void printState(State state) {
  switch (state) {
    case STATE_ALL_LOW:
      Serial.println("All inputs LOW");
      break;
    case STATE_INPUT_1_HIGH:
      Serial.println("Input 1 HIGH, Others LOW");
      break;
    case STATE_INPUT_2_HIGH:
      Serial.println("Input 2 HIGH, Others LOW");
      break;
    case STATE_INPUT_2_1_HIGH:
      Serial.println("Input 2 and 1 HIGH, Others LOW");
      break;
    case STATE_INPUT_3_HIGH:
      Serial.println("Input 3 HIGH, Others LOW");
      break;
    case STATE_INPUT_3_1_HIGH:
      Serial.println("Input 3 and 1 HIGH, Others LOW");
      break;
    case STATE_INPUT_3_2_HIGH:
      Serial.println("Input 3 and 2 HIGH, Others LOW");
      break;
    case STATE_INPUT_3_2_1_HIGH:
      Serial.println("Input 3, 2, and 1 HIGH");
      break;
    case STATE_INPUT_4_HIGH:
      Serial.println("Input 4 HIGH, Others LOW");
      break;
    case STATE_INPUT_4_1_HIGH:
      Serial.println("Input 4 and 1 HIGH, Others LOW");
      break;
    case STATE_INPUT_4_2_HIGH:
      Serial.println("Input 4 and 2 HIGH, Others LOW");
      break;
    case STATE_INPUT_4_2_1_HIGH:
      Serial.println("Input 4, 2, and 1 HIGH");
      break;
    case STATE_INPUT_4_3_HIGH:
      Serial.println("Input 4 and 3 HIGH, Others LOW");
      break;
    case STATE_INPUT_4_3_1_HIGH:
      Serial.println("Input 4, 3, and 1 HIGH");
      break;
    case STATE_INPUT_4_3_2_HIGH:
      Serial.println("Input 4, 3, and 2 HIGH");
      break;
    case STATE_INPUT_4_3_2_1_HIGH:
      Serial.println("Input 4, 3, 2, and 1 HIGH");
      break;
    case STATE_INPUT_5_HIGH:
      Serial.println("Input 5 HIGH, Others LOW");
      break;
    case STATE_INPUT_5_1_HIGH:
      Serial.println("Input 5 and 1 HIGH, Others LOW");
      break;
    case STATE_INPUT_5_2_HIGH:
      Serial.println("Input 5 and 2 HIGH, Others LOW");
      break;
    case STATE_INPUT_5_2_1_HIGH:
      Serial.println("Input 5, 2, and 1 HIGH");
      break;
    case STATE_INPUT_5_3_HIGH:
      Serial.println("Input 5 and 3 HIGH, Others LOW");
      break;
    case STATE_INPUT_5_3_1_HIGH:
      Serial.println("Input 5, 3, and 1 HIGH");
      break;
    case STATE_INPUT_5_3_2_HIGH:
      Serial.println("Input 5, 3, and 2 HIGH");
      break;
    case STATE_INPUT_5_3_2_1_HIGH:
      Serial.println("Input 5, 3, 2, and 1 HIGH");
      break;
    case STATE_INPUT_5_4_HIGH:
      Serial.println("Input 5 and 4 HIGH, Others LOW");
      break;
    case STATE_INPUT_5_4_1_HIGH:
      Serial.println("Input 5, 4, and 1 HIGH");
      break;
    case STATE_INPUT_5_4_2_HIGH:
      Serial.println("Input 5, 4, and 2 HIGH");
      break;
    case STATE_INPUT_5_4_2_1_HIGH:
      Serial.println("Input 5, 4, 2, and 1 HIGH");
      break;
    case STATE_INPUT_5_4_3_HIGH:
      Serial.println("Input 5, 4, and 3 HIGH");
      break;
    case STATE_INPUT_5_4_3_1_HIGH:
      Serial.println("Input 5, 4, 3, and 1 HIGH");
      break;
    case STATE_INPUT_5_4_3_2_HIGH:
      Serial.println("Input 5, 4, 3, and 2 HIGH");
      break;
    case STATE_ALL_HIGH:
      Serial.println("All inputs HIGH");
      break;
    default:
    
      Serial.println("Unknown state");
      break;
  }
}
