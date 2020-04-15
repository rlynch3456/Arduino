#ifndef RJLNeo_h
#define RJLNeo_h

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

class RJLNeo
{
  public:
    RJLNeo(int pin, int len);
    void setAll(byte red, byte green, byte blue);  

  private:
    int _pin;
    int _length;
    Adafruit_NeoPixel *_strip;
};

#endif
