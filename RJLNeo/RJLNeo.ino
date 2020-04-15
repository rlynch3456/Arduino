#include "RJLNeo.h"
#include "blob.h"

RJLNeo neo(6, 21);
Blob *blob1, *blob2;

void setup() {
  // put your setup code here, to run once:
  Adafruit_NeoPixel * strip = neo.getStrip();
  blob1 = new Blob(0, 4, 0, 255, 0, strip);
  Serial.begin(9600); // open the serial port at 9600 bps:
}

void loop() {

  // put your main code here, to run repeatedly:
#if 0
  neo.setAll(255, 0, 0);
  delay(1000);
  neo.setAll(0, 0, 0);
  delay(1000);
  neo.wipeFromStart(255, 0, 0, 100);
  neo.wipeFromStart(0, 0, 0, 100);
  delay(1000);
  neo.wipeFromEnd(0, 0, 255, 100);
  neo.wipeFromEnd(0, 0, 0, 100);

  neo.setAll(0, 0, 0);
  delay(1000);
#endif

  unsigned int stripLen, blobWidth;
  blob1->getWidth(&blobWidth);
  neo.getLength(&stripLen);

  for(int i = 0; i < stripLen - blobWidth; i++)
  {
    blob1->shift(1);
    blob1->setColor(255, 0, 0);
    delay(25);
  }
delay(1000);
  for(int i = 0; i < stripLen - blobWidth; i++)
  {
    blob1->shift(-1);
    blob1->setColor(0, 255, 0);
    delay(25);
  }
  delay(1000);
}
