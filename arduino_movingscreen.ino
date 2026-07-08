#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
int textPosition = 12;
const String message = "  67  ";

ArduinoLEDMatrix matrix;
void setup() {
  // put your setup code here, to run once:
matrix.begin();
}

void loop() {
matrix.beginDraw();
  
  matrix.stroke(0xFFFFFFFF); // Turn LEDs ON for text
  matrix.textFont(Font_5x7);
  
  // Draw the text at our custom X position
  matrix.beginText(textPosition, 1, 0xFFFFFFFF);
  matrix.print(message); 
  matrix.endText(); // Note: No SCROLL_LEFT here, we manage it manually
  
  matrix.endDraw();
  
  // Move the text 1 pixel to the left
  textPosition--;
  
  // Calculate when the text has completely walked off the left side of the screen
  // A 5x7 font is about 6 pixels wide per letter (including spaces)
  int messageWidth = message.length() * 6;
  
  // If the text is completely gone, reset it back to the right edge
  if (textPosition < -messageWidth) {
    textPosition = 12; // 12 is the right edge of the screen
  }
  
  delay(80); // Controls the scrolling speed (lower = faster, higher = slower)
}
