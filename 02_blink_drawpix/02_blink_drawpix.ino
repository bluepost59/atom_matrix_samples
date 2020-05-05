#include "M5Atom.h"

void setup() {
  M5.begin(true, false, true);
}

void loop() {
  for (uint32_t i = 0; i < 25;i++){
    M5.dis.drawpix(i, 0xf00000);
    delay(50);
  }

  for (uint32_t i = 0; i < 25; i++)
  {
    M5.dis.drawpix(i, 0x000000);
    delay(50);
  }
}
