#define BIT_COUNT 4
const unsigned int bitsLeds[BIT_COUNT] = {8, 9, 10, 11};
const unsigned long interval = 300;

void setup() {
  setupBits();
}

void loop() {
 
  bitCount();
  wave();

}

void setupBits() {
  for(unsigned int pin = 0; pin < BIT_COUNT; pin++){
      pinMode(bitsLeds[pin], OUTPUT);
  }
}

void bitsDigitalWrite(const unsigned int (&values)[BIT_COUNT]) {
  for(unsigned int pin = 0; pin < BIT_COUNT; pin++) {
      digitalWrite(bitsLeds[pin], values[pin]);
  }
}

void bitCount() {
  // 0
  bitsDigitalWrite({LOW, LOW, LOW, LOW});
  delay(interval);
  // 1
  bitsDigitalWrite({LOW, LOW, LOW, HIGH});
  delay(interval);
  // 2
  bitsDigitalWrite({LOW, LOW, HIGH, LOW});
  delay(interval);
  // 3
  bitsDigitalWrite({LOW, LOW, HIGH, HIGH});
  delay(interval);
  // 4
  bitsDigitalWrite({LOW, HIGH, LOW, LOW});
  delay(interval);
  // 5
  bitsDigitalWrite({LOW, HIGH, LOW, HIGH});
  delay(interval);
  // 6
  bitsDigitalWrite({LOW, HIGH, HIGH, LOW});
  delay(interval);
  // 7
  bitsDigitalWrite({LOW, HIGH, HIGH, HIGH});
  delay(interval);
  // 8
  bitsDigitalWrite({HIGH, LOW, LOW, LOW});
  delay(interval);
  // 9
  bitsDigitalWrite({HIGH, LOW, LOW, HIGH});
  delay(interval);
  // 10
  bitsDigitalWrite({HIGH, LOW, HIGH, LOW});
  delay(interval);
  // 11
  bitsDigitalWrite({HIGH, LOW, HIGH, HIGH});
  delay(interval);
  // 12
  bitsDigitalWrite({HIGH, HIGH, LOW, LOW});
  delay(interval);
  // 13
  bitsDigitalWrite({HIGH, HIGH, LOW, HIGH});
  delay(interval);
  // 14
  bitsDigitalWrite({HIGH, HIGH, HIGH, LOW});
  delay(interval);
  // 15
  bitsDigitalWrite({HIGH, HIGH, HIGH, HIGH});
  delay(interval);
}

void wave() {
  for (unsigned int i = 0; i < BIT_COUNT; i++) {
    unsigned int values[BIT_COUNT] = {LOW, LOW, LOW, LOW};
    values[i] = HIGH;  // Set the LED at position `i` to HIGH
    
    bitsDigitalWrite(values);
    delay(interval / 2);

  }
}