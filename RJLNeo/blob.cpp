#include "Arduino.h"
#include <Adafruit_NeoPixel.h>
#include "blob.h"

Blob::Blob(int start, unsigned int width, byte red, byte green, byte blue, Adafruit_NeoPixel *strip)
{
  _start = start;
  _width = width;
  _red = red;
  _green = green;
  _blue = blue;
  _strip = strip;
}

/*
 * Blob::draw()
 *
 * Display the blob with the current color;
 */

void Blob::draw()
{
  for(int i = 0; i < _width; i++)
    _strip->setPixelColor(_start + i, _red, _green, _blue);

  _strip->show();
  
}

/*
 * Blob::erase()
 *
 * Erase the blob by turning off all the pixels
 *
 */

void Blob::erase()
{
    for(int i = 0; i < _width; i++)
    _strip->setPixelColor(_start + i, 0, 0, 0);

  _strip->show();

}

/*
 * Blob::shift(int delta)
 *
 * Parameters:
 * int delta - positive or negative distance to shift
 *
 * Move the blob by the given amount, and redraw.
 * It is unchecked if the blob will go off either end of the strip.
 *
 */
void Blob::shift(int delta)
{
  // clear out the old pixels
  erase();

  _start = _start + delta;
  draw();
  _strip->show();
}

/*
 * Blob::moveTo(int i)
 *
 * Parameters:
 * int i - new position.
 * It is unchecked if the new position will be off either end of the strip
 *
 * Move the blob to a new position and redraw.
 *
 */

void Blob::moveTo(int i)
{
  // clear out the old position
  erase();

  _start = i;
  draw();
  _strip->show();
}

void Blob::setColor(byte red, byte green, byte blue)
{
  _red = red;
  _green = green;
  _blue = blue;
}

void Blob::setWidth(unsigned int width)
{
  _width = width;
}

void Blob::getColor(byte *red, byte *green, byte * blue)
{
  *red = _red;
  *green = _green;
  *blue = _blue;
}

void Blob::getStart(int *start)
{
  *start = _start;
}

void Blob::getWidth(unsigned int *width)
{
  *width = _width;
}
