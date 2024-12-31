#include <Servo.h>

uint8_t servoPin = 9;
uint8_t servoPos = 0;
uint8_t stepSize = 45;

const int buttonPin = 7;

bool toggle = false;

const uint8_t min_degree = 0;
const uint8_t max_degree = 180;
uint8_t currentDegree = 0;

Servo servito;

void setup() {

  currentDegree = 0;

  // Enable internal pull-up resistor for buttonPin
  pinMode(buttonPin, INPUT_PULLUP);  // Button reads HIGH when not pressed, LOW when pressed

  servito.attach(servoPin);
  servito.write(currentDegree);
  Serial.begin(9600);  // Start serial communication
}

void loop() {

  int buttonState = digitalRead(buttonPin);  // Read the button state

  if (buttonState == LOW) {  // Button pressed (active-low)
    // If button is pressed, update the servo position
    currentDegree = (currentDegree >= max_degree) ? min_degree : currentDegree + stepSize;

    servito.write(currentDegree);  // Move the servo
    Serial.print("Current degree: ");
    Serial.println(currentDegree);
    delay(500);  // Add a delay to debounce the button
  }

  delay(100);  // Small delay to reduce CPU usage
}
