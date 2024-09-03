#pragma once

#define RINGBUF_INTERNAL_BUFFER_SIZE 8

typedef struct ringbuf_s ringbuf_t;

struct ringbuf_s {
  char buf[RINGBUF_INTERNAL_BUFFER_SIZE];
  char* read_ptr;
  char* write_ptr;
};

typedef enum {
  RingbufGetStatusSuccess,
  RingbufGetStatusFailureBufferEmpty,
} ringbuf_get_status_t;

typedef enum {
  RingbufPushStatusSuccess,
  RingbufPushStatusFailureBufferFull,
} ringbuf_push_status_t;

void ringbuf_init(struct ringbuf_s* rb);
ringbuf_push_status_t ringbuf_push(struct ringbuf_s* rb, char item);
ringbuf_get_status_t ringbuf_get(struct ringbuf_s* rb, char* result);
