/*
  EL_Escudo.cpp - EL Escudo library
  Written by Ryan Owens for SparkFun Electronics

  This library is released under the 'Beer Me' license, so use it however you
  with. Just buy me a beer if we ever meet!
  
  ***
  
  Re-Written by Andy Durant
  for Arduino 1.0+
  with variable pulse width
  
*/

/******************************************************************************
 * Includes
 ******************************************************************************/

#include "Arduino.h"
#include "EL_Escudo.h"

/******************************************************************************
 * Definitions
 ******************************************************************************/

/******************************************************************************
 * Constructors
 ******************************************************************************/

/******************************************************************************
 * User API
 ******************************************************************************/

void EL_EscudoClass::on(int channel)
{
	digitalWrite(channel, HIGH); 
}

void EL_EscudoClass::off(int channel)
{
	digitalWrite(channel, LOW);
}

void EL_EscudoClass::all_on(void)
{
	for(int i=A; i<=H; i++){
	  EL.on(i);  
	}
}

void EL_EscudoClass::all_off(void)
{
	for(int i=A; i<=H; i++){
      EL.off(i);
    }
}

void EL_EscudoClass::fade_in(int chan, int pW)
{
	for(int brightness=0; brightness<=pW; brightness++){
		for(int duration=0; duration<5; duration++){
			on(chan);
			delay(brightness);
			off(chan);
			delay(pW-brightness);
		}
	}
	EL.on(chan);
}

void EL_EscudoClass::fade_out(int chan, int pW)
{
	for(int brightness=pW; brightness>=0; brightness--){
		for(int duration=0; duration<5; duration++){
			on(chan);
			delay(brightness);
			off(chan);
			delay(pW-brightness);
		}
	}
}

void EL_EscudoClass::pulse(int chan, int pW)
{
	EL.fade_in(chan, pW);
	EL.fade_out(chan, pW);
}

EL_EscudoClass EL;
