#include "HX711.h"

HX711::HX711(byte DT, byte SCK, byte GAIN)
  {
  dt   = DT;
  sck  = SCK;
  gain = GAIN;
  conf = 0;
  }

bool HX711::ready()
  {
  if (!conf)
    {
    pinMode(dt , INPUT);
    pinMode(sck, OUTPUT);
    conf   = 1;
    }
  return digitalRead(dt) == LOW;
  }

long HX711::read()
  {
  while (!ready());
  byte data[3];
  for (byte j = 3; j--;) { data[j] = shiftIn(dt, sck, MSBFIRST); }
  for (int  i = 0; i < gain; i++)
    {
    digitalWrite(sck, HIGH);
    digitalWrite(sck, LOW);
    }
  data[2] ^= 0x80;
  return ((uint32_t) data[2] << 16) | ((uint32_t) data[1] << 8) | (uint32_t) data[0];
}