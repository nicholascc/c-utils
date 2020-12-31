# c-utils

A set of small single-header-file libraries I use for my C projects.

### integer.h

Definitions for basic integer types: `u8`, `u16`, `u32`, `u64`, `i8`, `i16`, `i32`, and `i64`.

### darray.h

A generic implementation of a dynamic array, along with some functions for interacting with it. The macro is called using the type of the elements of the array, and a name for use in the functions. For example, `GENERATE_DARRAY_TYPE(u8, byte);` defines a struct `darray_byte` and its associated functions. The implementation provides the following definitions:

```c
struct darray_TYPE {
  u64 reserved; // Amount of space reserved (in terms of elements, not bytes)
  u64 length; // Amount of elements in array (not size in bytes)
  TYPE *data;
};

darray_TYPE initialize_darray_TYPE(u64 reserved); // Initializes the array

u64 darray_TYPE_size(darray_TYPE arr); // Gets the size of the array (length * sizeof(TYPE))

void darray_TYPE_push(darray_TYPE *arr, TYPE push_value); // Pushes a value to the end of the array.

TYPE darray_TYPE_push(darray_TYPE *arr); // Removes an element from the end of the array and returns its value.
```

###### Note: `darray.h` depends upon `integer.h`.
