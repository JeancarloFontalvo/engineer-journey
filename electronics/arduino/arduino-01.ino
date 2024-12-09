#define TIME_BASE_MS 100
#define LIMIT_INTERVAL_COUNT 10

uint8_t loop_count = 1;
uint16_t frequency = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  frequency = TIME_BASE_MS * loop_count;

  //blink(frequency);
  digitalWriteDelay(HIGH, frequency);
  digitalWriteDelay(LOW, 1000);

  loop_count++;

  if(loop_count > LIMIT_INTERVAL_COUNT) {
    loop_count = 1;
  }
}


void blink(unsigned long time) {
  unsigned long fase = time / 2;

  digitalWrite(13, HIGH);
  delay(fase);
  digitalWrite(13, LOW);
  delay(fase);
}

void digitalWriteDelay(uint8_t val, unsigned long time) {
  digitalWrite(13, val);
  delay(time);
}
