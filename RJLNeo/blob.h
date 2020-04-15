#ifndef Blob_h
#define Blob_h

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

class Blob
{

  public:
    Blob(int start, unsigned int width, byte red, byte green, byte blue, Adafruit_NeoPixel *strip);
    void draw();
    void shift(int delta);
    void setColor(byte red, byte green, byte blue);
    void setWidth(unsigned int width);
    void erase();
    void moveTo(int i);

/* getter functions */
    void getColor(byte *red, byte *green, byte * blue);
    void getStart(int *start);
    void getWidth(unsigned int *width);

  private:
    int _start;
    unsigned int _width;
    byte _red, _green, _blue;
    Adafruit_NeoPixel *_strip;



  
};


#endif
