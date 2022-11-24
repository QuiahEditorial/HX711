// Por Roberto A. Zavala
// Breve : https://es.overleaf.com/read/tdszxygbwjrc
// Libro : https://www.amazon.com.mx/dp/B074TTGLL2
// 🙏🏼    : DNv7acPAeVBhTXbKv26itJecPG1SPy2o4F

#include <HX711.h>

HX711 hx711(D2, D3, 1);  // (DT , SCK, gain= 1|3) de HX711

float p = 0;             // Peso
float b = 0;             // Corrige la medición del sensor a un valor de 0
float m = 2215.05;          // Pendiente obtenida de una masa conocida. Ajusta m para calibrar.
int   n = 10;

void setup()
  {
  Serial.begin(9600);
  Serial.println("Iniciando báscula m(g) :) ");
  for (int i=0; i<7;  i++) { hx711.read(); } // Mediciones erroneas mientras se inicia el sensor
  for (int i=0; i<10; i++) { b = b + hx711.read();}
  b = b/10;                                  // Se promedia el valor de b para reducir el error
  }

void loop()
  {
  p = 0;
  for (int i=0; i<n; i++) { p = p + ( hx711.read() - b) / m; }
  Serial.println( p/n , 2 );
  }
