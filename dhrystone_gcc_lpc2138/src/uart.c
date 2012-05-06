#include <string.h>

#include "../inc_lpc/lpc213x.h"                        /* LPC21xx definitions */
#include "../inc/target.h"
#include "../inc/uart.h"


volatile int  UART0Status;
volatile char UART0TxEmpty = 1;
volatile char UART0Buffer[BUFSIZE];
volatile int  UART0Count = 0;

/*****************************************************************************
 ** Function name:		UART0Handler
 **
 ** Descriptions:		UART0 interrupt handler
 **
 ** parameters:			None
 ** Returned value:		None
 **
 *****************************************************************************/
void UART0Handler (void)
{
  char IIRValue, LSRValue;
  char Dummy;

  IIRValue = U0IIR;

  IIRValue >>= 1;			/* skip pending bit in IIR */
  IIRValue &= 0x07;			/* check bit 1~3, interrupt identification */
  if ( IIRValue == IIR_RLS )		/* Receive Line Status */
    {
      LSRValue = U0LSR;
      /* Receive Line Status */
      if ( LSRValue & (LSR_OE|LSR_PE|LSR_FE|LSR_RXFE|LSR_BI) )
        {
          /* There are errors or break interrupt */
          /* Read LSR will clear the interrupt */
          UART0Status = LSRValue;
          Dummy = U0RBR;		/* Dummy read on RX to clear interrupt, then bail out */

          VICVectAddr = 0;		/* Acknowledge Interrupt */
          return;
        }
      if ( LSRValue & LSR_RDR )	/* Receive Data Ready */
        {
          /* If no error on RLS, normal ready, save into the data buffer. */
          /* Note: read RBR will clear the interrupt */
          UART0Buffer[UART0Count] = U0RBR;
          UART0Count++;
          if ( UART0Count == BUFSIZE )
            {
              UART0Count = 0;		/* buffer overflow */
            }

        }
    }
  else if ( IIRValue == IIR_RDA )	/* Receive Data Available */
    {
      /* Receive Data Available */
      UART0Buffer[UART0Count] = U0RBR;
      UART0Count++;
      if ( UART0Count == BUFSIZE )
        {
          UART0Count = 0;		/* buffer overflow */
        }

      UART0Count--;
    }
  else if ( IIRValue == IIR_CTI )	/* Character timeout indicator */
    {
      /* Character Time-out indicator */
      UART0Status |= 0x100;		/* Bit 9 as the CTI error */
    }
  else if ( IIRValue == IIR_THRE )	/* THRE, transmit holding register empty */
      {
        /* THRE interrupt */
        LSRValue = U0LSR;		/* Check status in the LSR to see if
					valid data in U0THR or not */
        if ( LSRValue & LSR_THRE )
          {
            UART0TxEmpty = 1;
          }
        else
          {
            UART0TxEmpty = 0;
          }
      }

  VICVectAddr = 0;		/* Acknowledge Interrupt */
}

/*****************************************************************************
 ** Function name:		UARTInit
 **
 ** Descriptions:		Initialize UART0 port, setup pin select,
 **				clock, parity, stop bits, FIFO, etc.
 **
 ** parameters:			UART baudrate
 ** Returned value:		true or false, return false only if the
 **				interrupt handler can't be installed to the
 **				VIC table
 **
 *****************************************************************************/
int  UARTInit( int  baudrate )
{
  int  Fdiv;

  PINSEL0 |= 0x05;              /* Enable RxD1 and TxD1, RxD0 and TxD0 */

  U0IER = 0x01;                 // disable all interrupts
  U0IIR = 0x00;                 // clear interrupt ID register
  U0LSR = 0x00;                 // clear line status register

  U0LCR = 0x83;                         /* 8 bits, no Parity, 1 Stop bit    */
  Fdiv = ( Fpclk / 16 ) / baudrate ;	/*baud rate */
  U0DLM =  Fdiv / 0xFF;
  U0DLL =  Fdiv % 0xFF;
  U0LCR = 0x03;                 /* DLAB = 0                         */
  U0FCR = 0x47;		        /* Enable and reset TX and RX FIFO. */
                                /* Interrupt on each character received */

  U0IER = IER_RBR | IER_THRE | IER_RLS;	/* Enable UART0 interrupt */

  VICVectAddr0 = (unsigned)UART0Handler ;
  VICVectCntl0 = 0x20 | 6;
  VICIntEnable = (1<<6);

  return 1;
}

/*****************************************************************************
 ** Function name:		UARTSend
 **
 ** Descriptions:		Send a block of data to the UART 0 port based
 **				on the data length
 **
 ** parameters:			buffer pointer, and data length
 ** Returned value:		None
 **
 *****************************************************************************/
void UARTSend(char *BufferPtr, int  length )
{
  if (length <= 0)
    {
      length = strlen(BufferPtr);
    }
  while ( length != 0 )
    {
      while ( !UART0TxEmpty );	/* THRE status, contain valid data */

      U0THR = *BufferPtr;
      UART0TxEmpty = 0;	/* not empty in the THR until it shifts out */

      BufferPtr++;
      length--;
    }
  return;
}

/*****************************************************************************
 ** Function name:              UARTSend
 **
 ** Descriptions:               Send a block of data to the UART 0 port based
 **                             on the data length
 **
 ** parameters:                 buffer pointer, and data length
 ** Returned value:             None
 **
 *****************************************************************************/
void puts_UART(char *BufferPtr)
{
  UARTSend( BufferPtr, 0);
}


/******************************************************************************
 **                            End Of File
 ******************************************************************************/
