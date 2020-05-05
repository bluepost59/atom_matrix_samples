#include "M5Atom.h"

void setup() {
  // put your setup code here, to run once:
  M5.begin(true, false, true);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (uint32_t i = 0; i < 25;i++){
    M5.dis.drawpix(i, 0xf00000);
    delay(50);
  }
  // delay(500);

  for (uint32_t i = 0; i < 25; i++)
  {
    M5.dis.drawpix(i, 0x000000);
    delay(50);
  }
  // delay(500);
}
