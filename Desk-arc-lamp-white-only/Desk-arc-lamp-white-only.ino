//This project is for an electronics workbench lighing set up. The electronics workbench will use an ATX power supply.
//As ATX power supplies require 10 watts of draw before they will turn on as a safety precation, this lighting setup will use those 10 watts in a productive manner.
//The plan is to use an Adafruit 5v Pro along with two sets of RGBW LEDs, a 1 meter 30 light strand and a 24 light ring on a magnifier.
//Each will be turned on independently by one of two buttons that will be connected to the Trinket. I may also connect a 5v cooling fan.
//Pin 6 will be the control pin for the 30 LED strand. The button will be on Pin 12.
//Pin 5 will be the control pin for the 24 LED ring. The button will be on Pin 10
//The sequence will be, when a button is pushed, the light controlled by it will cycle through all its colors before going to a slightly blueish white.


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif



#define PIN 6

#define NUM_LEDS 24

#define BRIGHTNESS 50 //default value is 50

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);


void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {


  
  // Some example procedures showing how to display to the pixels:
  colorWipe(strip.Color(255, 0, 0), 50); // Red
  colorWipe(strip.Color(0, 255, 0), 50); // Green
  colorWipe(strip.Color(0, 0, 255), 50); // Blue
  colorWipe(strip.Color(0, 0, 0, 255), 50); // White 
  colorWipe(strip.Color(255, 255, 255, 255), 50); // All
  colorWipe(strip.Color(255, 255, 255, 255), 90); // All
  // fullWhite();
  // delay(2000);



}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }


}

