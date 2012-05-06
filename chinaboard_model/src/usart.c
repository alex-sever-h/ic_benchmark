/*
 * uart.c
 *
 *  Created on: Apr 12, 2012
 *      Author: alexs
 */

#include <unistd.h>

#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"
#include "usart.h"
#include "rbuffer.h"


#ifdef BUFFERED
volatile FIFO_buffer u1rx, u1tx;
#endif

void usart_init( int baudrate )
{
#ifdef BUFFERED

  buffer_init (&u1rx);
  buffer_init (&u1tx);

#endif

  RCC_APB2PeriphClockCmd(   RCC_APB2Periph_USART1 |
      RCC_APB2Periph_GPIOA  |
      RCC_APB2Periph_AFIO,
      ENABLE);

  //GPIO_PinRemapConfig(GPIO_Remap_USART1, ENABLE);

  // start with pin configuration
  GPIO_InitTypeDef GPIO_init;

  GPIO_init.GPIO_Pin   = GPIO_Pin_10;
  GPIO_init.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
  GPIO_init.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_init);

  GPIO_init.GPIO_Pin   = GPIO_Pin_9;
  GPIO_init.GPIO_Mode  = GPIO_Mode_AF_PP;
  GPIO_init.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_init);


#ifdef BUFFERED

  NVIC_InitTypeDef NVIC_init;

  NVIC_init.NVIC_IRQChannel                   = USART1_IRQn;
  NVIC_init.NVIC_IRQChannelCmd                = ENABLE;
  NVIC_init.NVIC_IRQChannelPreemptionPriority = 0x0F;
  NVIC_init.NVIC_IRQChannelSubPriority        = 0x0F;

  NVIC_Init (&NVIC_init);

  //disable Transmit Data Register empty interrupt
  USART_ITConfig(USART1, USART_IT_TXE, DISABLE);
  //enable Receive Data register not empty interrupt
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);

#endif

  // usart peripheral confguration
  USART_InitTypeDef USART_init;
  USART_ClockInitTypeDef USART_clockinit;

  USART_ClockStructInit(&USART_clockinit);
  USART_ClockInit(USART1, &USART_clockinit);

  USART_init.USART_BaudRate   = baudrate;
  USART_init.USART_WordLength = USART_WordLength_8b;
  USART_init.USART_Parity     = USART_Parity_No;
  USART_init.USART_Mode       = USART_Mode_Rx | USART_Mode_Tx;
  USART_init.USART_StopBits   = USART_StopBits_1;
  USART_init.USART_HardwareFlowControl = USART_HardwareFlowControl_None;

  USART_Init(USART1, &USART_init);
  USART_Cmd(USART1, ENABLE);

}


void USART1_IRQHandler(void)
{
  uint8_t ch;

  //if Receive interrupt
  if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
    {
      ch=(uint8_t)USART_ReceiveData(USART1);
      //put char to the buffer
      buffer_put(&u1rx, ch);
    }

  if (USART_GetITStatus(USART1, USART_IT_TXE) != RESET)
    {
      if (buffer_get(&u1tx, &ch) == SUCCESS)
        {
          //if char read from buffer
          USART_SendData(USART1, ch);
        }
      else
        {
          //if buffer empty

          //disable Transmit Data Register empty interrupt
          USART_ITConfig(USART1, USART_IT_TXE, DISABLE);
        }
    }
}



void usart1_put(uint8_t ch)
{
#ifdef BUFFERED
  //put char to the buffer
  buffer_put(&u1tx, ch);
  //enable Transmit Data Register empty interrupt
  USART_ITConfig(USART1, USART_IT_TXE, ENABLE);
#else
  USART_SendData(USART1, (uint8_t) ch);
  //Loop until the end of transmission
  while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
    {
    }
#endif
}


uint8_t usart1_get(void)
{
#ifdef BUFFERED
  uint8_t ch;
  //check if buffer is empty
  while (buffer_empty(&u1rx) == SUCCESS);
  buffer_get(&u1rx, &ch);
  return ch;
#else
  while ( USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
  return (uint8_t)USART_ReceiveData(USART1);
#endif
}


void usart_puts(const char * string)
{
#ifdef BUFFERED
  while(*string)
    {
      buffer_put(&u1tx, *string);
      string++;
    }
  USART_ITConfig(USART1, USART_IT_TXE, ENABLE);

#else
  while(*string)
    {
      usart1_put(*string);
      string++;
    }
#endif
}

















