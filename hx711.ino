#include <HX711.h>

HX711 hx711(D2, D3, 1);  // puertos y ganancia (DT , SCK, gain= 1|3)

void setup() 
{
Serial.begin(9600);
}

void loop() 
{
Serial.println(hx711.read());
delay(500);
}
