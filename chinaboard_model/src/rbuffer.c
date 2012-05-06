/*
 * rbuffer.c
 *
 *  Created on: Apr 12, 2012
 *      Author: alexs
 */

#include "rbuffer.h"


inline void buffer_init(volatile FIFO_buffer *buffer)
{
  buffer->count = 0;
  buffer->in    = 0;
  buffer->out   = 0;
}

inline int buffer_put(volatile FIFO_buffer *buffer, uint8_t c)
{
  while (buffer->count == USARTBUFFSIZE);
    //return FAILURE;

  buffer->data[buffer->in++]=c;
  buffer->count++;

  if (buffer->in == USARTBUFFSIZE)
    buffer->in=0;

  return SUCCESS;
}

inline int buffer_get(volatile FIFO_buffer *buffer, uint8_t *c)
{
  if (buffer->count == 0)
    return FAILURE;

  *c = buffer->data[buffer->out++];
  buffer->count--;

  if (buffer->out == USARTBUFFSIZE)
    buffer->out = 0;

  return SUCCESS;
}

inline int buffer_empty(volatile FIFO_buffer *buffer)
{
  if (buffer->count == 0)
    return SUCCESS;
  else
    return FAILURE;

}



































