
#ifndef __UART_H 
#define __UART_H

#include "../inc/irq.h"

#define IER_RBR		0x01
#define IER_THRE	0x02
#define IER_RLS		0x04

#define IIR_PEND	0x01
#define IIR_RLS		0x03
#define IIR_RDA		0x02
#define IIR_CTI		0x06
#define IIR_THRE	0x01

#define LSR_RDR		0x01
#define LSR_OE		0x02
#define LSR_PE		0x04
#define LSR_FE		0x08
#define LSR_BI		0x10
#define LSR_THRE	0x20
#define LSR_TEMT	0x40
#define LSR_RXFE	0x80

#define BUFSIZE		0x10

int  UARTInit    ( int Baudrate );
void UART0Handler( void ) __irq ;
void UARTSend    ( char * BufferPtr, int Length );


void puts_UART(char *BufferPtr);




extern volatile int  UART0Status;
extern volatile char UART0TxEmpty;
extern volatile char UART0Buffer[BUFSIZE];
extern volatile int  UART0Count;


#endif /* end __UART_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
