#include "ringbuf/ringbuf.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(push_get, pushes_an_element_and_receives_it) {
  ringbuf_t rb = {0};
  ringbuf_init(&rb);

  ringbuf_push(&rb, 15);

  char result;
  ringbuf_get_status_t status;

  status = ringbuf_get(&rb, &result);
  cr_expect_eq(status, RingbufGetStatusSuccess);
  cr_expect_eq(result, 15);

  status = ringbuf_get(&rb, &result);
  cr_expect_eq(status, RingbufGetStatusFailureBufferEmpty);
}

Test(push_full, fail_if_pushing_to_full_buffer) {
  ringbuf_t rb = {};
  ringbuf_init(&rb);

  for (int i = 0; i < 8; i++)
    ringbuf_push(&rb, 15);

  ringbuf_push_status_t status = ringbuf_push(&rb, 15);

  cr_expect_eq(status, RingbufPushStatusFailureBufferFull);
}

Test(get_empty, fail_if_getting_from_empty_buffer) {
  ringbuf_t rb = {};
  ringbuf_init(&rb);

  char result;
  ringbuf_get_status_t status = ringbuf_get(&rb, &result);

  cr_expect_eq(status, RingbufGetStatusFailureBufferEmpty);
}

Test(push_cycles, cycles) {
  ringbuf_t rb = {};
  ringbuf_init(&rb);

  for (int i = 0; i < 8; i++)
    ringbuf_push(&rb, i);

  char result;
  for (int i = 0; i < 8; i++)
    ringbuf_get(&rb, &result);

  ringbuf_push_status_t push_status = ringbuf_push(&rb, 69);
  ringbuf_get_status_t get_status = ringbuf_get(&rb, &result);

  cr_expect_eq(push_status, RingbufPushStatusSuccess);
  cr_expect_eq(get_status, RingbufGetStatusSuccess);
  cr_expect_eq(result, 69);
}
