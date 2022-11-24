// Por Roberto A. Zavala
// Breve : https://es.overleaf.com/read/tdszxygbwjrc
// Libro : https://www.amazon.com.mx/dp/B074TTGLL2
// 🙏🏼    : DNv7acPAeVBhTXbKv26itJecPG1SPy2o4F

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
