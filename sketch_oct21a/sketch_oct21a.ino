#include <TM1638.h>

TM1638 a(D2, D1, D0);

void setup() {
a.setLEDs(0xdd);
a.setDisplayToDecNumber(273,0);

}

void loop() {
  // put your main code here, to run repeatedly:

}
