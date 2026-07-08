#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;
// This is our 2D framework frame (12 columns, 8 rows)
// 0 means OFF, 1 means ON
uint8_t frame[8][12] = {0}; 

// REUSABLE HELPER FUNCTION
void drawPixel(int x, int y, bool state) {
  // Safety check: Make sure the coordinates actually fit on the 12x8 screen
  if (x >= 0 && x < 12 && y >= 0 && y < 8) {
    frame[y][x] = state ? 1 : 0; // Update the pixel in our digital layout
  }
}

void setup() {
  matrix.begin();
}

void loop() {
  // Clear the frame array to all zeros first (turns everything off)
  memset(frame, 0, sizeof(frame));

  // Example 1: Light up the top-left pixel (0, 0)
  drawPixel(0, 0, true);
  
  // Example 2: Light up a pixel near the middle (5, 4)
  drawPixel(5, 4, true);
  
  // Example 3: Light up the bottom-right pixel (11, 7)
  drawPixel(11, 7, true);

  // FIXED: Send our 2D array to the screen using renderBitmap
  matrix.renderBitmap(frame, 8, 12);
  
  delay(1000); 
}