#include <Wire.h>                  // I2C communication library
#include <Adafruit_GFX.h>           // Core graphics library
#include <Adafruit_SSD1306.h>       // OLED driver library

#define SCREEN_WIDTH 128            // OLED display width, in pixels
#define SCREEN_HEIGHT 64            // OLED display height, in pixels

// Define the I2C address of the OLED screen
#define OLED_RESET    -1            // No reset pin used
#define SCREEN_ADDR    0x3C        // OLED I2C address (common: 0x3C or 0x3D)

// Initialize the display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define FACE_WIDTH    16
#define FACE_HEIGHT   16

// 'face-1', 16x16px
const unsigned char face_face_1 [] PROGMEM = {
	0x00, 0x00, 0x1f, 0xf8, 0x20, 0x04, 0x40, 0x02, 0x40, 0x02, 0x4c, 0x02, 0x4c, 0x32, 0x4c, 0x32, 
	0x4c, 0x32, 0x4c, 0x02, 0x40, 0x02, 0x40, 0x02, 0x40, 0x02, 0x20, 0x04, 0x1f, 0xf8, 0x00, 0x00
};
// 'face-2', 16x16px
const unsigned char face_face_2 [] PROGMEM = {
	0x00, 0x00, 0x1f, 0xf8, 0x20, 0x04, 0x40, 0x02, 0x40, 0x02, 0x40, 0x32, 0x4c, 0x32, 0x4c, 0x32, 
	0x4c, 0x32, 0x40, 0x32, 0x40, 0x02, 0x40, 0x02, 0x40, 0x02, 0x20, 0x04, 0x1f, 0xf8, 0x00, 0x00
};
// 'face-3', 16x16px
const unsigned char face_face_3 [] PROGMEM = {
	0x00, 0x00, 0x1f, 0xf8, 0x20, 0x04, 0x40, 0x02, 0x40, 0x02, 0x40, 0x02, 0x40, 0x02, 0x40, 0x02, 
	0x4e, 0x72, 0x40, 0x02, 0x40, 0x02, 0x40, 0x02, 0x40, 0x02, 0x20, 0x04, 0x1f, 0xf8, 0x00, 0x00
};
// 'face-4', 16x16px
const unsigned char face_face_4 [] PROGMEM = {
	0x00, 0x00, 0x1f, 0xf8, 0x20, 0x04, 0x48, 0x12, 0x50, 0x0a, 0x40, 0x02, 0x4e, 0x3a, 0x4c, 0x32, 
	0x4e, 0x3a, 0x40, 0x02, 0x40, 0x02, 0x40, 0x82, 0x40, 0x02, 0x20, 0x04, 0x1f, 0xf8, 0x00, 0x00
};
// 'face-5', 16x16px
const unsigned char face_face_5 [] PROGMEM = {
	0x00, 0x00, 0x1f, 0xf8, 0x20, 0x04, 0x40, 0x02, 0x40, 0x02, 0x40, 0x02, 0x40, 0x02, 0x4c, 0x32, 
	0x50, 0x0a, 0x40, 0x02, 0x44, 0x22, 0x43, 0xc2, 0x40, 0x02, 0x20, 0x04, 0x1f, 0xf8, 0x00, 0x00
};

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 240)
const int face_allArray_LEN = 5;
const unsigned char* face_allArray[5] = {
	face_face_1,
	face_face_2,
	face_face_3,
	face_face_4,
	face_face_5
};


int currentFaceIndex = 0;  // Track which face to display

void setup() {

  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDR)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  
  display.clearDisplay(); // Clear display before showing the face
}

void loop() {
  // Display current face
  drawFace(face_allArray[currentFaceIndex]);
  delay(1000);  // Wait for 2 seconds
  
  // Move to the next face in the array
  currentFaceIndex = (currentFaceIndex + 1) % 5;  // Loop through 5 faces
}

void drawFace(const unsigned char* face) {
  display.clearDisplay();  // Clear the display
  
  // Draw the 16x16 face bitmap at the top-left corner of the 128x32 OLED
  display.drawBitmap(
    (display.width()  - FACE_WIDTH ) / 2,
    (display.height() - FACE_HEIGHT) / 2, 
    face, 
    FACE_WIDTH, FACE_HEIGHT, 
    WHITE
  );
  
  display.display();  // Refresh the display with the new face
}
