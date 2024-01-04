//const int relayOne = 2;
//const int relayTwo = 3;
//const int relayThree = 4;
//const int relayFour = 5;
//const int switchPin = 13;
//
//void setup() {
//  Serial.begin(115200);
//  pinMode(relayOne, OUTPUT);
//  pinMode(relayTwo, OUTPUT);
//  pinMode(relayThree, OUTPUT);
//  pinMode(relayFour, OUTPUT);
//  pinMode(switchPin, INPUT_PULLUP);
//
//  // Initialize relay states
//  digitalWrite(relayOne, LOW);
//  digitalWrite(relayTwo, LOW);
//  digitalWrite(relayThree, LOW);
//  digitalWrite(relayFour, LOW);
//}
//
//void loop() {
//  // Read the state of the switch
//  int switchState = digitalRead(switchPin);
//    // Check if the switch is turned off
//    if (switchState == HIGH) {
//    // Turn off all relays
//    digitalWrite(relayOne, LOW);
//    digitalWrite(relayTwo, LOW);
//    digitalWrite(relayThree, LOW);
//    digitalWrite(relayFour, LOW);
//    } else {
//      // Control relays based on the switch state
//      digitalWrite(relayOne, HIGH);
//      delay(1000);
//      digitalWrite(relayTwo, HIGH);
//      delay(1000);
//      digitalWrite(relayThree, HIGH);
//      delay(1000);
//      digitalWrite(relayFour, HIGH);
//      delay(1000);
//    }
//
//    if (switchState == HIGH) {
//    // Turn off all relays
//    digitalWrite(relayOne, LOW);
//    digitalWrite(relayTwo, LOW);
//    digitalWrite(relayThree, LOW);
//    digitalWrite(relayFour, LOW);
//    }
//
//  // Add a delay for readability and to avoid excessive Serial output
//  //delay(1000);  
//}

const int relayOne = 2;
const int relayTwo = 3;
const int relayThree = 4;
const int relayFour = 5;
const int switchPin = 13;

int relayIndex = 0;
unsigned long lastActivationTime = 0;
const unsigned long activationInterval = 1000; // Adjust this interval as needed

void setup() {
  pinMode(relayOne, OUTPUT);
  pinMode(relayTwo, OUTPUT);
  pinMode(relayThree, OUTPUT);
  pinMode(relayFour, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);

  // Initialize relay states
  digitalWrite(relayOne, LOW);
  digitalWrite(relayTwo, LOW);
  digitalWrite(relayThree, LOW);
  digitalWrite(relayFour, LOW);
}

void loop() {
  // Read the state of the switch
  int switchState = digitalRead(switchPin);

  // Check if the switch is turned off
  if (switchState == HIGH) {
    // Turn off all relays
    digitalWrite(relayOne, LOW);
    digitalWrite(relayTwo, LOW);
    digitalWrite(relayThree, LOW);
    digitalWrite(relayFour, LOW);
    relayIndex = 0; // Reset relay index
  } else {
    // Control relays based on the switch state and timing
    unsigned long currentTime = millis();
    if (currentTime - lastActivationTime >= activationInterval) {
      // Activate the current relay
      switch (relayIndex) {
        case 0:
          digitalWrite(relayOne, HIGH);
          break;
        case 1:
          digitalWrite(relayTwo, HIGH);
          break;
        case 2:
          digitalWrite(relayThree, HIGH);
          break;
        case 3:
          digitalWrite(relayFour, HIGH);
          break;
      }

      // Increment the relay index
      relayIndex = (relayIndex + 1) % 4;

      // Update the last activation time
      lastActivationTime = currentTime;
    }
  }
}
