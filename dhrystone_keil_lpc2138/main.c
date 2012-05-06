/*
 * main.c
 *
 *  Created on: Mar 14, 2012
 *      Author: alexs
 */

#include <lpc213x.h>
#include "target.h"
#include "uart.h"
#include "timer.h"
#include "benchmark.h"

#include <stdlib.h>

void init_chip(void);


int main(void)
{
  init_chip();
  init_counter_ms();

  UARTInit(115200);
  UARTSend("--------------UART INITIALIZED--------------\n\n", 0);

  while(1)
    start_benchmark();

  return 0;
}


void feed(void)
{
  PLLFEED=0xAA;
  PLLFEED=0x55;
}

void init_chip(void)
{

  // Enabling PLL

  PLLCFG=PLLCFG_VAL;
  feed();

  PLLCON=0x1;
  feed();

  while(!(PLLSTAT & 0x400)) ;

  PLLCON=0x3;
  feed();

  // Enabling MAM

  MAMCR=0x0;
  MAMTIM=0x2;
  MAMCR=0x2;

  // Enabling Fpclk = Fcclk

  VPBDIV=APBDIV_VAL;

}

