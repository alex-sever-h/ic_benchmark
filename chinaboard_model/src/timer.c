#include "timer.h"
#include "stm32f10x.h"

void init_counter_ms()
{
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

  RCC_ClocksTypeDef RCC_clocks;
  RCC_GetClocksFreq(&RCC_clocks);


  uint32_t prescaler = 2 * RCC_clocks.PCLK1_Frequency / 1000 ;


  TIM_TimeBaseInitTypeDef  TIM_init;

  TIM_init.TIM_ClockDivision     = TIM_CKD_DIV1;
  TIM_init.TIM_CounterMode       = TIM_CounterMode_Up;
  TIM_init.TIM_Period            = 0xFFFF;
  TIM_init.TIM_Prescaler         = 0;

  TIM_TimeBaseInit(TIM3, &TIM_init);

  TIM_PrescalerConfig(TIM3, prescaler, TIM_PSCReloadMode_Immediate);

  TIM_Cmd(TIM3, ENABLE);

}

void reset_counter()
{

}

unsigned int read_counter()
{
  return TIM_GetCounter(TIM3);        //read time
}
