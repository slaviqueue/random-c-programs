#include "ringbuf.h"
#include <string.h>

void ringbuf_init(struct ringbuf_s* rb) {
  memset(rb, 0, RINGBUF_INTERNAL_BUFFER_SIZE);
  rb->read_ptr = rb->buf;
  rb->write_ptr = rb->buf;
}

ringbuf_push_status_t ringbuf_push(struct ringbuf_s* rb, char item) {
  char* next = rb->write_ptr + 1;

  if (next >= rb->buf + RINGBUF_INTERNAL_BUFFER_SIZE)
    next = rb->buf;

  if (next == rb->read_ptr)
    return RingbufPushStatusFailureBufferFull;

  rb->write_ptr = next;
  *rb->write_ptr = item;

  return RingbufPushStatusSuccess;
}

ringbuf_get_status_t ringbuf_get(struct ringbuf_s* rb, char* result) {
  if (rb->write_ptr == rb->read_ptr)
    return RingbufGetStatusFailureBufferEmpty;

  char* next = rb->read_ptr + 1;

  if (next >= rb->buf + RINGBUF_INTERNAL_BUFFER_SIZE)
    next = rb->buf;

  rb->read_ptr = next;
  *result = *rb->read_ptr;

  return RingbufGetStatusSuccess;
}
