/*
 * neopixel_rgb_knob
 * 
 * This is a test program to adjust the rgb of a strip of
 * neopixels useing three potentiometers.
 */

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 8

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

/* Set up three potentiometers to adjust the rgb colors */
#define knob_r 0
#define knob_g 1
#define knob_b 2



void setup() {
  // put your setup code here, to run once:
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
 
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

}

void loop() {
  // put your main code here, to run repeatedly:
  int r, g, b;

  /* Get each of the rgb values and then map from 0-1023 to 0-255. */

  r = analogRead(knob_r);
  r = map(r, 0, 1023, 0, 255);

  g = analogRead(knob_g);
  g = map(g, 0, 1023, 0, 255);

  b = analogRead(knob_b);
  b = map(b, 0, 1023, 0, 255);

  /* set all of the pixels to the same color */
  setAll(r, g, b);
  
}

/* Simple function to set all of the neopixels to the same color */
void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < LED_COUNT; i++ ) {
    strip.setPixelColor(i, red, green, blue);
  }
  strip.show();
}
