#include "timer.h"
#include "target.h"
#include <lpc213x.h>

void init_counter_ms()
{   
  T0TCR  = 0x1;         //counter enable
  T0PR   = Fpclk / 1000;  //prescaler set to count ms
}

void reset_counter()
{
  T0TCR = 0x3;          //reset to 0
  T0TCR = 0x1;          //restart
}

unsigned int read_counter()
{
  return T0TC;        //read time
}
