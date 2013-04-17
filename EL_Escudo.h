/*
  EL_Escudo.h - EL Escudo library
  Written by Ryan Owens for SparkFun Electronics

  This library is released under the 'Beer Me' license, so use it however you
  with. Just buy me a beer if we ever meet!
  
  ***
  
  Re-Written by Andy Durant
  for Arduino 1.0+
  with variable pulse width
  
*/

#ifndef EL_Escudo_h
#define EL_Escudo_h

#include <inttypes.h>

#define A  2
#define B  3
#define C  4
#define D  5
#define E  6
#define F  7
#define G  8
#define H  9
#define STATUS  10
#define pulse_width  15

class EL_EscudoClass
{
  public:
  void on(int);
  void off(int);
  void all_on(void);
  void all_off(void);
  void set_pulse(int);
  void fade_in(int, int pW = pulse_width);
  void fade_out(int, int pW = pulse_width);
  void pulse(int, int pW = pulse_width);
};

extern EL_EscudoClass EL;

#endif

