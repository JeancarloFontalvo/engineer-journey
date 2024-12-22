#include <Servo.h>

uint8_t servoPin = 9;
uint8_t servoPos = 0;
uint8_t stepSize = 10;
bool toggle = false;

Servo servito;

void setup() {
  servito.attach(servoPin);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  servito.write(servoPos);
  servoPos += stepSize * (toggle ? -1 : 1);
  delay(50);

  if(servoPos >= 180 || servoPos <= 0) {
    toggle = !toggle;
  }
}
