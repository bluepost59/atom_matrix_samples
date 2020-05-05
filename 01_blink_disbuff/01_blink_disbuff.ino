#include "M5Atom.h"

uint8_t DisBuff[2 + 5 * 5 * 3];

void setup() {
  M5.begin(true, false, true);
}

void loop() {
  DisBuff[0] = 0x05;
  DisBuff[1] = 0x05;

  for (int i = 0; i < 25;i++){
    DisBuff[2 + i * 3 + 0] = 0x20;
    DisBuff[2 + i * 3 + 1] = 0x00;
    DisBuff[2 + i * 3 + 2] = 0x00;
  }

  M5.dis.displaybuff(DisBuff);
  delay(1000);

  for (int i = 0; i < 25; i++)
  {
    DisBuff[2 + i * 3 + 0] = 0x00;
    DisBuff[2 + i * 3 + 1] = 0x00;
    DisBuff[2 + i * 3 + 2] = 0x00;
  }

  M5.dis.displaybuff(DisBuff);
  delay(1000);
}
