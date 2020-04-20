#ifndef RJLNeo_h
#define RJLNeo_h

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

class RJLNeo
{
  public:
    RJLNeo(int pin, unsigned int len);
    RJLNeo(int pin, unsigned int len, byte red, byte green, byte blue);
    void setAll(byte red, byte green, byte blue);
    void wipeFromStart(byte red, byte green, byte blue, int timeDelay);
    void wipeFromEnd(byte red, byte green, byte blue, int timeDelay);
    void getBackgroundColor(byte *red, byte *green, byte *blue);
    Adafruit_NeoPixel * getStrip();
    void getLength(unsigned int *len);
    void draw(int start, int width, byte red, byte green, byte blue);
    void erase(int start, int width);
    void setBackground();

  private:
    int _pin;
    int _length;
    byte _red, _green, _blue;
    Adafruit_NeoPixel *_strip;
};

#endif
