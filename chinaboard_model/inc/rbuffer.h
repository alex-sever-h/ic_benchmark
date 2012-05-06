/*
 * rbuffer.h
 *
 *  Created on: Apr 12, 2012
 *      Author: alexs
 */

#ifndef RBUFFER_H_
#define RBUFFER_H_

#include <stdint.h>

#define FAILURE 0
#define SUCCESS 1

#define USARTBUFFSIZE 128

typedef struct{
  uint8_t in;
  uint8_t out;
  uint8_t count;

  uint8_t data[USARTBUFFSIZE];
}FIFO_buffer;


void buffer_init   (volatile FIFO_buffer *buffer);
int  buffer_put    (volatile FIFO_buffer *buffer, uint8_t  c);
int  buffer_get    (volatile FIFO_buffer *buffer, uint8_t *c);
int  buffer_empty  (volatile FIFO_buffer *buffer);




#endif /* RBUFFER_H_ */
