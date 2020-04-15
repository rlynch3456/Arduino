#include "Arduino.h"
#include <Adafruit_NeoPixel.h>
#include "blob.h"

Blob::Blob(int start, int width, byte red, byte green, byte blue, Adafruit_NeoPixel *strip)
{
  _start = start;
  _width = width;
  _red = red;
  _green = green;
  _blue = blue;
  _strip = strip;
}

void Blob::draw()
{
  for(int i = 0; i < _width; i++)
    _strip->setPixelColor(_start + i, _red, _green, _blue);

  _strip->show();
  
}
