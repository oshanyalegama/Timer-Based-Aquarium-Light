int pin = 13;  // The pin we're using
int ledPin = 12;
int pin1 = 4; // green
int pin2 = 5; // yellow
int pin3 = 6; // red
long duration1 = 10000;  // The duration for button 1 (1 minute)
long duration2 = 20000;  // The duration for button 2 (5 minutes)
long duration3 = 30000;  // The duration for button 3 (30 minutes)
int buttonPin1 = A0;  // The pin for button 1
int buttonPin2 = A1;  // The pin for button 2
int buttonPin3 = A2;  // The pin for button 3
int buttonPin4 = A3; //the toggle pin
bool buttonState1 = false;  // The state of button 1 (pressed or not pressed)//A0,23, 8H
bool buttonState2 = false;  // The state of button 2 (pressed or not pressed)//A1,24
bool buttonState3 = false;  // The state of button 3 (pressed or not pressed)//A2.25
unsigned long startTime;  // The time the pin was turned on

unsigned long pressTime;
bool reset = false;

int buttonState = 0;        // variable for storing the button state
int ledState = LOW; 

int resetTime = 5000;

void setup() {
  pinMode(pin, OUTPUT);  // Set the pin as an output
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);  // Set the button 1 pin as an input with pullup resistor
  pinMode(buttonPin2, INPUT_PULLUP);  // Set the button 2 pin as an input with pullup resistor
  pinMode(buttonPin3, INPUT_PULLUP);  // Set the button 3 pin as an input with pullup resistor
  pinMode(buttonPin4, INPUT_PULLUP);
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  buttonState1 = digitalRead(buttonPin1);  // Read the state of button 1
  buttonState2 = digitalRead(buttonPin2);  // Read the state of button 2
  buttonState3 = digitalRead(buttonPin3);  // Read the state of button 3
  buttonState = digitalRead(buttonPin4);

//  digitalWrite(ledPin, HIGH);
//  delay(1000); // Wait for 1 second
//
//  // Turn the LED off
//  digitalWrite(ledPin, LOW);
//  delay(1000); // Wait for 1 second
//  
  if (buttonState == LOW) {
    ledState = !ledState;
    digitalWrite(pin, ledState);
    delay(500);  // Debounce delay to prevent rapid toggling
  }
  
  if (buttonState1 == LOW) {  // If button 1 is pressed
    digitalWrite(pin1, HIGH);
    digitalWrite(pin, HIGH);  // Turn the pin on
    startTime = millis();  // Store the time the pin was turned on
    while (millis() - startTime <= duration1) {  // While the pin should be on
//      digitalWrite(ledPin, HIGH);
//      delay(1000); // Wait for 1 second
//
//      // Turn the LED off
//      digitalWrite(ledPin, LOW);
//      delay(1000); // Wait for 1 second
  
      //RESET Code
      buttonState = digitalRead(buttonPin4);
      if (buttonState == LOW){
        pressTime = millis();
        reset = true;
        while (millis() - pressTime <= resetTime){
          buttonState = digitalRead(buttonPin4);
          if (buttonState == HIGH){
            
            reset = false;
          }
        }
        if (reset){
          Serial.println("Stopped");
          break;
        }
      }
      //TIME PRINTING CODE
      Serial.print("Time remaining: ");
      Serial.print((duration1 - (millis() - startTime)) / 1000);  // Calculate and print the time remaining
      Serial.println(" seconds");
      delay(1000);  // Wait for one second
    }
    digitalWrite(pin1, LOW);
    digitalWrite(pin, LOW);  // Turn the pin off
    Serial.println("Done");  // Print a message when the pin is turned off
    delay(1000);  // Wait for a second before starting again
  }
  
  if (buttonState2 == LOW) {  // If button 1 is pressed
    digitalWrite(pin2, HIGH);
    digitalWrite(pin, HIGH);  // Turn the pin on
    startTime = millis();  // Store the time the pin was turned on
    while (millis() - startTime <= duration2) {  // While the pin should be on
      //COLOUR CHANGING CODE
      if (millis() - startTime >= (duration2- duration1)) {
        digitalWrite(pin2, LOW);
        digitalWrite(pin1, HIGH);
      }
//      digitalWrite(ledPin, HIGH);
//      delay(1000); // Wait for 1 second
//
//      // Turn the LED off
//      digitalWrite(ledPin, LOW);
//      delay(1000); // Wait for 1 second
  
      //RESET Code
      buttonState = digitalRead(buttonPin4);
      if (buttonState == LOW){
        pressTime = millis();
        reset = true;
        while (millis() - pressTime <= resetTime){
          buttonState = digitalRead(buttonPin4);
          if (buttonState == HIGH){
            
            reset = false;
          }
        }
        if (reset){
          Serial.println("Stopped");
          break;
        }
      }
      Serial.print("Time remaining: ");
      Serial.print((duration2 - (millis() - startTime)) / 1000);  // Calculate and print the time remaining
      Serial.println(" seconds");
      delay(1000);  // Wait for one second
    }
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, LOW);
    digitalWrite(pin, LOW);  // Turn the pin off
    Serial.println("Done");  // Print a message when the pin is turned off
    delay(1000);  // Wait for a second before starting again
  }

  if (buttonState3 == LOW) {  // If button 1 is pressed
    digitalWrite(pin3, HIGH);
    digitalWrite(pin, HIGH);  // Turn the pin on    
    startTime = millis();  // Store the time the pin was turned on
    while (millis() - startTime <= duration3) {  // While the pin should be on
      //COLOUR CHANGING CODE
      if (millis() - startTime >= (duration3-duration2)) {
        if (millis() - startTime >= (duration3 - duration1)) {
           digitalWrite(pin2, LOW);
           digitalWrite(pin1, HIGH);
        }
        else{
           digitalWrite(pin3, LOW);
           digitalWrite(pin2, HIGH);
        }
      }
//      digitalWrite(ledPin, HIGH);
//      delay(1000); // Wait for 1 second
//
//      // Turn the LED off
//      digitalWrite(ledPin, LOW);
//      delay(1000); // Wait for 1 second
//  
      //RESET Code
      buttonState = digitalRead(buttonPin4);
      if (buttonState == LOW){
        pressTime = millis();
        reset = true;
        while (millis() - pressTime <= resetTime){
          buttonState = digitalRead(buttonPin4);
          if (buttonState == HIGH){
            
            reset = false;
          }
        }
        if (reset){
          Serial.println("Stopped");
          break;
        }
      }
      Serial.print("Time remaining: ");
      Serial.print((duration3 - (millis() - startTime)) / 1000);  // Calculate and print the time remaining
      Serial.println(" seconds");
      delay(1000);  // Wait for one second
    }
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, LOW);
    digitalWrite(pin, LOW);  // Turn the pin off
    Serial.println("Done");  // Print a message when the pin is turned off
    delay(1000);  // Wait for a second before starting again
  }
}
