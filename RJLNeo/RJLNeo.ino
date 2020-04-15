#include "RJLNeo.h"

RJLNeo neo(6, 21);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  neo.setAll(255, 0, 0);
  delay(1000);
  neo.setAll(0, 0, 0);
  delay(1000);
  neo.wipeFromStart(255, 0, 0, 100);
  neo.wipeFromStart(0, 0, 0, 100);
  delay(1000);
  neo.wipeFromEnd(0, 0, 255, 100);
  neo.wipeFromEnd(0, 0, 0, 100);

}
