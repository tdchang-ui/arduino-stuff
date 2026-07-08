#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

uint8_t frame[8][12] = {
  {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
  {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1}, 
  {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}, 
  {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1}, 
  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}  
};

void setup() {
  matrix.begin();
}

void loop() {
 
  matrix.renderBitmap(frame, 8, 12);
  
  delay(1000); 
}