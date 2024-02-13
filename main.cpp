// constants won't change
const int BUTTON_PIN = 7;  
const int LED_PIN    = 13;       
const int FLASH_LED_PIN = 5; // Pin for flashing LED

// variables will change:
int ledState = LOW;        // tracks the current state of LED
int lastButtonState;        // the previous state of button
int currentButtonState; // the current state of button
unsigned long previousMillis = 0;  // store the last time the LED was updated
const long interval = 100;  // interval at which to blink (milliseconds)

void setup() {
  Serial.begin(9600);                         // initialize serial
  pinMode(BUTTON_PIN, INPUT);  // set arduino pin to input mode
  pinMode(LED_PIN, OUTPUT);      // set arduino pin to output mode
  pinMode(FLASH_LED_PIN, OUTPUT); // set arduino pin to output mode for flashing LED
  currentButtonState = digitalRead(BUTTON_PIN);
}
  
void loop() {
  
  lastButtonState    = currentButtonState;                // save the last state
  currentButtonState = digitalRead(BUTTON_PIN); // read new state
  
  if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.print("The button is pressed: ");
  
    // toggle state of LED
    if(ledState == LOW) {
       ledState = HIGH;  
       Serial.println(" Turning red LED on");
    }
    else {
      ledState = LOW;
      Serial.println(" Turning red LED off");
    }
 
    // control LED according to the toggled state
    digitalWrite(LED_PIN, ledState);  //turns the LED on or off based on the variable
  }

  // Flashing LED
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    flashLED();
  }
}

void flashLED() {
  static bool flashState = LOW; // Static variable to maintain state between calls
  digitalWrite(FLASH_LED_PIN, flashState);
  flashState = !flashState; // Toggle the state for next call
}
