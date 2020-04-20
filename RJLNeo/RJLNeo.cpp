#include "Arduino.h"
#include <Adafruit_NeoPixel.h>
#include "RJLNeo.h"

RJLNeo::RJLNeo(int pin, unsigned int len)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _length = len;

  _strip = new Adafruit_NeoPixel;
  _strip->setPin(_pin);
  _strip->updateLength(_length);
  _strip->setBrightness(25);

  // set background to default black
  _red = 0;
  _green = 0;
  _blue = 0;
  
}

RJLNeo::RJLNeo(int pin, unsigned int len, byte red, byte green, byte blue)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _length = len;

  _strip = new Adafruit_NeoPixel;
  _strip->setPin(_pin);
  _strip->updateLength(_length);
  _strip->setBrightness(25);

  // set background to default black
  _red = red;
  _green = green;
  _blue = blue;
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

void RJLNeo::setBackground()
{
  for(int i = 0; i < _length; i++ )
  {
    _strip->setPixelColor(i, _red, _green, _blue);
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

Adafruit_NeoPixel * RJLNeo::getStrip()
{
  return _strip;
}

void RJLNeo::getLength(unsigned int * len)
{
  *len = _length;
}

void RJLNeo::draw(int start, int width, byte red, byte green, byte blue)
{
  for(int i = 0; i < width; i++)
    _strip->setPixelColor(start + i, red, green, blue);

  _strip->show();
}

void RJLNeo::erase(int start, int width)
{
  for(int i = 0; i < width; i++)
    _strip->setPixelColor(start + i, _red, _green, _blue);

  _strip->show();
}

void RJLNeo::getBackgroundColor(byte *red, byte *green, byte *blue)
{
  *red = _red;
  *green = _green;
  *blue = _blue;
}
