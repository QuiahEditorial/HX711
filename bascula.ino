// Por Roberto A. Zavala
// Breve : https://es.overleaf.com/read/tdszxygbwjrc
// Libro : https://www.amazon.com.mx/dp/B074TTGLL2
// 🙏🏼    : DNv7acPAeVBhTXbKv26itJecPG1SPy2o4F

#include <HX711.h>

HX711 hx711(D2, D3, 1);  // (DT , SCK, gain= 1|3) de HX711

float p;                                                             // masa en gramos
float b = 0;                                            // valor inicial en y = m x +b
float m = 2215.05;                                         // pendiente en y = m x + b
int   n = 10;                                                // mediciones a promediar

void setup()
  {
  Serial.begin(9600);
  Serial.println("Iniciando báscula m(g) :) ");
  for (int i=0; i<7;  i++) { hx711.read(); }        // ignorar las primeras mediciones
  for (int i=0; i<10; i++) { b = b + hx711.read();}                    // se obtiene b
  b = b/10;
  }

void loop()
  {
  p = 0;
  for (int i=0; i<n; i++) { p = p + ( hx711.read() - b) / m; }
  Serial.println( p/n , 2 );
  }
