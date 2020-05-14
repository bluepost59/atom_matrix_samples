#include "WiFi.h"
#include "M5Atom.h"

const char *ssid = "myssid";
const char *password = "mypassword";

uint8_t DisBuff[2+5*5*3];

void setup(){
    WiFi.disconnect(false,true);

    M5.begin(true, true, true);
    WiFi.begin(ssid, password);

    DisBuff[0] = 0x05;
    DisBuff[1] = 0x05;

    for (int i = 0; i < 25; i++)
    {
        DisBuff[2 + i * 3 + 0] = 0x20;
        DisBuff[2 + i * 3 + 1] = 0x00;
        DisBuff[2 + i * 3 + 2] = 0x00;
    }

    M5.dis.displaybuff(DisBuff);

    while(WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print(".");
    }

    for (int i = 0; i < 25; i++)
    {
        DisBuff[2 + i * 3 + 0] = 0x00;
        DisBuff[2 + i * 3 + 1] = 0x20;
        DisBuff[2 + i * 3 + 2] = 0x00;
    }

    M5.dis.displaybuff(DisBuff);
    Serial.println(WiFi.localIP());
}

void loop(){
    
}