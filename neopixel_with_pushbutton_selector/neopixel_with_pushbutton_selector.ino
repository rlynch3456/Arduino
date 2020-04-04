/*
 * neopixel_with_pushbutton_selector
 * 
 * This is a test program to do different effects
 * with noepoixels selecting pushbutton
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

/* do we want Serial output? */
//#define DEBUG

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)


/* We will be using an interrupt to change colors */
const byte interruptPin = 2;
volatile byte state = HIGH;
long debounce_time = 250;
volatile unsigned long last_micros = 0;
int r, g, b;
unsigned long lastState;

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

  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), interrupt, FALLING);
  last_micros = micros();

  randomSeed(analogRead(0));
#ifdef DEBUG
  Serial.begin(9600);
#endif
  r = random(0, 255);
  g = random(0, 255);
  b = random(0, 255);

  lastState = state;
  setAll(r, g, b);

}

void loop() {
  // put your main code here, to run repeatedly:
#ifdef DEBUG
  Serial.print("micros(): ");
  Serial.println((unsigned long)micros());
#endif
  /* Did the state change (did the button get pressed)? */
  if(lastState != state) {
    lastState = state;
    setAll(r, g, b);
  }
}


/* Do something everytime the interrupt is received */
void interrupt(){

  /* We have to take into account that the program has been running for 
   *  a long time, so micros() could have looped back around to zero.  This
   *  happens abut every 70 minutes.
   */

  unsigned long curr_micros = (long)micros();
#ifdef DEBUG
  Serial.print("curr_micros: ");
  Serial.println(curr_micros);
  Serial.print("last_miros: ");
  Serial.println(last_micros);
  Serial.println();
#endif  
  if(((unsigned long)(curr_micros - last_micros) >= debounce_time * 1000) || (unsigned long)(curr_micros < last_micros)){
    state = !state;
    last_micros = curr_micros;
    changeColor();
  }
}

/* Change the global rgb colors */
void changeColor() {
  r = random(0, 255);
  g = random(0, 255);
  b = random(0, 255);  
}


/* Set all of the pixels to specified rgb color */
void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < LED_COUNT; i++ ) {
    strip.setPixelColor(i, red, green, blue);
  }
  strip.show();
}
