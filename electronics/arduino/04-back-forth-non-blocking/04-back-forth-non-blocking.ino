const int numLEDs = 4;                // Number of LEDs
const int maxInterval = 150;    
const int intervalInit = 50;    
int ledPins[] = {8, 9, 10, 11};      // LED pin numbers (adjust as necessary)
int currentLED = 0;                   // Current LED to be lit
int direction = 1;  
int backAndFortLoop = 0;

unsigned long previousMillis = 0;     // Store the last time an LED was toggled
unsigned long interval = intervalInit; // Interval for LED switch (in milliseconds)
        

void setup() {
  // Initialize LED pins
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);  // Set LED pins as outputs
    digitalWrite(ledPins[i], LOW);  // Initially turn off all LEDs
  }
}

void loop() {
  unsigned long currentMillis = millis();  // Get the current time

  // If enough time has passed, toggle LEDs
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Save the last time the LED was toggled

    // Turn off the current LED
    digitalWrite(ledPins[currentLED], LOW);

    // Update the current LED index based on direction
    currentLED += direction;

    // Reverse direction if we reach the ends
    if (currentLED == numLEDs - 1 || currentLED == 0) {
      direction = -direction;  // Reverse direction
    }

    // Turn on the new LED
    digitalWrite(ledPins[currentLED], HIGH);

    backAndFortLoop++;

    if(backAndFortLoop >= numLEDs * 2) {
      interval += 10;
      backAndFortLoop = 0;
    }
    
  }

  if(interval > maxInterval) {
    interval = intervalInit;
  }
}
