#include <Wire.h>                  // I2C communication library
#include <Adafruit_GFX.h>           // Core graphics library
#include <Adafruit_SSD1306.h>       // OLED driver library

#define SCREEN_WIDTH 128            // OLED display width, in pixels
#define SCREEN_HEIGHT 64            // OLED display height, in pixels

// Define the I2C address of the OLED screen
#define OLED_RESET    -1            // No reset pin used
#define SCREEN_ADDR    0x3C        // OLED I2C address (common: 0x3C or 0x3D)
#define ENABLE_LOG     false
#define MAX_INPUT 1023
#define DELAY 0

int previousDx = 0;
int previousDy = 0;

struct Cursor {
  int x; 
  int y;
  int previousX;
  int previousY;
  bool toggleX;
  bool hasToggled;
};


uint8_t cursorPin = A0;
uint8_t cursorDirectionPin = 7;

Cursor cursor = {0, 0, 0, 0, false, false};

// Initialize the display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// 'cursor-8x8', 8x8px
const unsigned char epd_bitmap_cursor_8x8 [] PROGMEM = {
	0x00, 0x18, 0x34, 0x34, 0x72, 0x7a, 0x66, 0x00
};

// 'cursor-16x16', 16x16px
const unsigned char epd_bitmap_cursor_16x16 [] PROGMEM = {
	0x01, 0x80, 0x03, 0x40, 0x02, 0x40, 0x05, 0x20, 0x06, 0x20, 0x0d, 0x10, 0x0a, 0x10, 0x15, 0x08, 
	0x1a, 0x08, 0x35, 0x04, 0x2a, 0x04, 0x55, 0x02, 0x6b, 0x82, 0x5e, 0x72, 0x60, 0x0e, 0x00, 0x00
};

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 80)
const int epd_bitmap_allArray_LEN = 2;
const unsigned char* epd_bitmap_allArray[2] = {
	epd_bitmap_cursor_8x8,
	epd_bitmap_cursor_16x16
};

const uint8_t bitmapSizes[2] = {8, 16};

int currentBitmap = 0;  // Track which face to display

void setup() {

  pinMode(cursorPin, INPUT);
  pinMode(cursorDirectionPin, INPUT);
  // Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDR)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay();
  Serial.println("");
  Serial.println("init cursor");
  updateCursor();
  Serial.println("----");
  delay(2000);
}

void loop() {

  updateCursor();
  logCursor();
  
  display.clearDisplay();

  drawCursor(epd_bitmap_allArray[1], bitmapSizes[1]);  

  display.display();
  delay(DELAY);
}

void updateCursor() {
  
  auto cursorVal = MAX_INPUT - analogRead(cursorPin);
  auto cursorToggleVal = digitalRead(cursorDirectionPin);
  auto xVal = map(cursorVal, 0, MAX_INPUT, 0, SCREEN_WIDTH);
  auto yVal = map(cursorVal, 0, MAX_INPUT, 0, SCREEN_HEIGHT);
  
  auto dx = xVal - cursor.x;
  auto dy = yVal - cursor.y;
  auto hasChangeX = dx != previousDx;
  auto hasChangeY = dy != previousDy;

  Serial.print("x: "); Serial.print(xVal); Serial.print(", previousX: "); Serial.print(cursor.previousX); Serial.print(", dx: "); Serial.print(dx); Serial.print(", previousDx: "); Serial.print(previousDx);
  Serial.println("");
  Serial.print("y: "); Serial.print(yVal); Serial.print(", previousY: "); Serial.print(cursor.previousY); Serial.print(", dy: "); Serial.print(dy); Serial.print(", previousDy: "); Serial.print(previousDy);

  Serial.println("");
  Serial.print("has changed x: "); Serial.print(hasChangeX);
  Serial.print("\nhas changed y: "); Serial.print(hasChangeY);
  Serial.println("");

  previousDx = dx;
  previousDy = dy;
  

  if(cursorToggleVal == HIGH) {
    cursor.toggleX = !cursor.toggleX;
    cursor.hasToggled = true;
    delay(200);
  }

  if(cursor.toggleX) {

    cursor.previousY = cursor.y;
    cursor.y += dy;
  }
  else {
    cursor.previousX = cursor.x;
    cursor.x += dx;
  }

  if(cursor.hasToggled) {
    cursor.hasToggled = false;
  }
}

void logCursor() {

  if(!ENABLE_LOG) return;

  Serial.print("cursor value: { "); 
  Serial.print("x: "); Serial.print(cursor.x); 
  Serial.print(", "); Serial.print("y: "); Serial.print(cursor.y);
  Serial.print(", "); Serial.print("previousX: "); Serial.print(cursor.previousX);
  Serial.print(", "); Serial.print("previousY: "); Serial.print(cursor.previousY);
  Serial.print(", "); Serial.print("toggleX: "); Serial.print(cursor.toggleX);
  Serial.print(", "); Serial.print("hasToggled: "); Serial.print(cursor.toggleX);
  Serial.println("}"); 
}

void drawCursor(const unsigned char* face, uint8_t bitmapSize) {
    
  // Draw the 16x16 face bitmap at the top-left corner of the 128x32 OLED
  display.drawBitmap(
    cursor.x,
    cursor.y, 
    face, 
    bitmapSize, 
    bitmapSize, 
    WHITE
  );   
}
