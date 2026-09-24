const uint8_t IN1 = 6;
const uint8_t IN2 = 7;

const uint8_t IN3 = 3;
const uint8_t IN4 = 4;

const uint8_t MIN_SPEED = 50;
const uint8_t MAX_SPEED = 255;

const uint8_t MAX_CYCLE_COUNT = 10;
uint8_t cycle = 0;
bool directionToggle = true;

struct Motor {
  uint8_t forwardPin;
  uint8_t backwardPin;
  uint8_t speed;
};

Motor motor1 = {IN1, IN2, MAX_SPEED};
Motor motor2 = {IN3, IN4, MAX_SPEED};


void setup() {
  pinMode(motor1.forwardPin, OUTPUT);
  pinMode(motor1.backwardPin, OUTPUT);
  pinMode(motor2.forwardPin, OUTPUT);
  pinMode(motor2.backwardPin, OUTPUT);

}

void loop() {

  moveForward(motor1);
  moveForward(motor2);


  // if (directionToggle) {
  //   moveForward(motor1);
  //   moveForward(motor2);
  // } else {
  //   moveBackward(motor1);
  //   moveBackward(motor2);
  // }

  // cycle++;
  // delay(200);

  // if (cycle > MAX_CYCLE_COUNT) {
  //   cycle = 0;
  //   directionToggle = !directionToggle;
  //   stopMotors();
  //   delay(1000);
  // }

}

void moveForward(Motor m) {
  digitalWrite(m.forwardPin, HIGH);
  digitalWrite(m.backwardPin, LOW);
}

void moveBackward(Motor m) {
  digitalWrite(m.forwardPin, LOW);
  digitalWrite(m.backwardPin, HIGH);
}

void stopMotors() {
  digitalWrite(motor1.forwardPin, LOW);
  digitalWrite(motor1.backwardPin, LOW);
  digitalWrite(motor2.forwardPin, LOW);
  digitalWrite(motor2.backwardPin, LOW);
}
