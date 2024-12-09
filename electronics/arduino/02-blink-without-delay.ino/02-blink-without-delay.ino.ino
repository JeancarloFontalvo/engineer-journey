#define BIT_COUNT 4
const unsigned int bitsLeds[BIT_COUNT] = {8, 9, 10, 11};
const unsigned long delay = 1000;

void setup() {
  for(unsigned int pin = 0; i < BIT_COUNT; i++){
      pinMode(bitsLeds[pin], OUTPUT);
  }
}

void loop() {
  // 0
  bitsDigitalWrite({LOW, LOW, LOW, LOW});
  delay(delay);
  // 1
  bitsDigitalWrite({LOW, LOW, LOW, HIGH});
  delay(delay);
  // 2
  bitsDigitalWrite({LOW, LOW, HIGH, LOW});
  delay(delay);
  // 3
  bitsDigitalWrite({LOW, LOW, LOW, LOW});
  delay(delay);
  // 4
  bitsDigitalWrite({LOW, LOW, LOW, LOW});
  delay(delay);
  // 5
  bitsDigitalWrite({LOW, LOW, LOW, LOW});
  delay(delay);
  // 6
  bitsDigitalWrite({LOW, LOW, LOW, LOW});
  delay(delay);
  // 7
  bitsDigitalWrite({LOW, LOW, LOW, LOW});
  delay(delay);
  // 8
  bitsDigitalWrite({LOW, LOW, LOW, LOW});
  delay(delay);
  // 9
  bitsDigitalWrite({LOW, LOW, LOW, LOW});
  delay(delay);
  // 10
  bitsDigitalWrite({LOW, LOW, LOW, LOW});
  delay(delay);
  // 11
  bitsDigitalWrite({LOW, LOW, LOW, LOW});
  delay(delay);
  // 12
  bitsDigitalWrite({LOW, LOW, LOW, LOW});
  delay(delay);
  // 13
  bitsDigitalWrite({LOW, LOW, LOW, LOW});
  delay(delay);
  // 14
  bitsDigitalWrite({LOW, LOW, LOW, LOW});
  delay(delay);
  // 15
  bitsDigitalWrite({LOW, LOW, LOW, LOW});
  delay(delay);

}

void bitsDigitalWrite(unsigned int* values) {
  for(unsigned int pin = 0; i < BIT_COUNT; i++) {
      digitalWrite(bitsLeds[pin], values[pin]);
  }
}
