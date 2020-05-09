// for GROVE temperature sensor v1.2
//   https://wiki.seeedstudio.com/Grove-Temperature_Sensor_V1.2/

#include "M5Atom.h"

const int pin_temperature = 25;

const int B = 4275;
const int R0 = 100000;

float read_temperature(int pin_number);

void setup()
{
    M5.begin(true, false, true);
    Serial.print("\nhello\n");
}

void loop()
{
    float temperture = read_temperature(pin_temperature);

    for (uint32_t i = 0; i < 25; i++)
    {
        M5.dis.drawpix(i, 0xf00000);
        delay(25);
    }
    // delay(500);

    for (uint32_t i = 0; i < 25; i++)
    {
        M5.dis.drawpix(i, 0x000000);
        delay(25);
    }
    // delay(500);
}

float read_temperature(int pin_number){
    int raw_temperature = analogRead(pin_number);
    float R = 1023.0 / (raw_temperature/4.0) -1.0;

    float temperature = 1.0 / (log(R)/ B + 1 / 298.15) - 275.15;

    Serial.println(temperature);

    return temperature;
}