#ifndef HX711_h
#define HX711_h
#include "Arduino.h"

class HX711
  {
  private:
    int  dt;
    int  sck;
    int  gain;
    bool conf;

  public:
    HX711(byte DT, byte SCK, byte GAIN);
    bool ready();
    long read();
  };

#endif