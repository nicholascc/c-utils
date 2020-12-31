#ifndef C_UTILS_DARRAY_H
#define C_UTILS_DARRAY_H

#include <stdlib.h>
#include <assert.h>

#include "integer.h"

#define GENERATE_DARRAY_TYPE(TYPE,TYPE_NAME) \
typedef struct darray_##TYPE_NAME { \
  u64 reserved; \
  u64 length; \
  TYPE *data; \
} darray_##TYPE_NAME; \
 \
darray_##TYPE_NAME initialize_darray_##TYPE_NAME(u64 reserved) { \
  assert(reserved % 2 == 0 && "reserve size must be a multiple of 2"); \
  darray_##TYPE_NAME r; \
  r.reserved = reserved; \
  r.length = 0; \
  r.data = malloc(r.reserved * sizeof(TYPE)); \
  assert(r.data != NULL && "initial dynamic array malloc failed"); \
  return r; \
} \
 \
u64 darray_##TYPE_NAME##_size(darray_##TYPE_NAME arr) { \
  return arr.length * sizeof(TYPE); \
} \
 \
void darray_##TYPE_NAME##_push(darray_##TYPE_NAME *arr, TYPE push_value) { \
  if(arr->length == arr->reserved) { \
    arr->reserved += arr->reserved / 2; \
    arr->data = realloc(arr->data, arr->reserved * sizeof(TYPE)); \
    assert(arr->data != NULL && "realloc to expand dynamic array failed"); \
  } \
  arr->data[arr->length] = push_value; \
  arr->length++; \
} \
 \
TYPE darray_##TYPE_NAME##_pop(darray_##TYPE_NAME *arr) { \
  assert(arr->length > 0 && "failed to pop; dynamic array has 0 elements"); \
  arr->length--; \
  return arr->data[arr->length]; \
}

// End of huge GENERATE_DARRAY_TYPE macro

#endif
