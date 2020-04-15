#ifndef Blob_h
#define Blob_h

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

class Blob
{

  public:
    Blob(int start, int width, byte red, byte green, byte blue, Adafruit_NeoPixel *strip);
    void draw();
    void shift(int delta);
    void setColor(byte red, byte green, byte blue);

  private:
    int _start;
    int _width;
    byte _red, _green, _blue;
    Adafruit_NeoPixel *_strip;



  
};


#endif
