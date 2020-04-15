#include "Arduino.h"
#include <Adafruit_NeoPixel.h>
#include "RJLNeo.h"

RJLNeo::RJLNeo(int pin, int len)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _length = len;

  _strip = new Adafruit_NeoPixel;
  _strip->setPin(_pin);
  _strip->updateLength(_length);
  _strip->setBrightness(25);
  
}

/* Set all of the pixels to specified rgb color */
void RJLNeo::setAll(byte red, byte green, byte blue)
{
  for(int i = 0; i < _length; i++ )
  {
    _strip->setPixelColor(i, red, green, blue);
  }
  _strip->show();
}

void RJLNeo::wipeFromStart(byte red, byte green, byte blue, int timeDelay)
{
  int i;

  // fill the strip
  for( i = 0; i < _length; i++)
  {
    _strip->setPixelColor(i, red, green, blue);
    _strip->show();
    delay(timeDelay);
  }
}

void RJLNeo::wipeFromEnd(byte red, byte green, byte blue, int timeDelay)
{
  int i;

  // fill the strip
  for( i = _length; i >=  0; i--)
  {
    _strip->setPixelColor(i, red, green, blue);
    _strip->show();
    delay(timeDelay);
  }
}
