// Include the Neopixel library

#include <Adafruit_NeoPixel.h>

// Declare and initialise global GPIO pin constant for Neopixel ring
const byte neoPin = 10;

// Declare and initialise global constant for number of pixels
const byte neoPixels = 24;

// Declare and initialise variable for Neopixel brightness
byte neoBright = 100;

// Create new Neopixel ring object
Adafruit_NeoPixel ring = Adafruit_NeoPixel(neoPixels, neoPin, NEO_GRB);

void setup() {
  // Initialise the ring
  ring.begin();
  ring.setBrightness(neoBright);
  ring.show();  
}

void loop() {
  // Turn on pixels
  for(int i = 0; i < neoPixels; i++){
    ring.setPixelColor(i, ring.Color(50,70,20));
    ring.show();
    delay(200);
  }

  // Turn off pixels
  for(int i = 0; i < neoPixels; i++){
    ring.setPixelColor(i, ring.Color(2,5,20));
    ring.show();
    delay(20);
  }
}
