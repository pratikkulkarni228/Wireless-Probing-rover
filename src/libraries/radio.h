/*
	Author: Swapnil Pathak
	Purpose: A minimal implementation of a library that
		 can be used by RF434 for communication
		 between it's Rx and Tx modules.
*/

#ifndef RADIO_H
#define RADIO_H

#include <stdlib.h>
#include <Arduino.h>

extern "C"
{
  extern void set_pins(uint8_t pin_rx, uint8_t pin_tx);
  extern void setup(uint16_t speed);
  
  extern void rf_begin();
  extern void rf_end();
  
  extern uint8_t send_data(uint8_t *buffer, uint8_t length);
  
  extern uint8_t recv_data(uint8_t *buffer, uint8_t *length);
  
}

#endif
