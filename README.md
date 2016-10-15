# cvec

A no bullshit type-safe vector library for C that supports operator `[]` for
indexing.

## Example
```c
#include "cvec.h"

int *x = NULL; /* initialize to NULL, replace *int* with any type you want */

vector_push(x, 100);
vector_push(x, 200);
vector_push(x, 300);

/* standard [] lookup of values */
printf("%d, %d, %d", x[0], x[1], x[2]);

/* free memory */
vector_free(x);
```

## How it works
Metadata of a vector is stored as a header behind the pointer exactly
`sizeof(vector_t)` behind. This is how operator `[]` can still be used for
indexing. Type safety is provided by having the pointer encode the type
via the language itself. No strange `void*` tricks. Though the generic resize
functions sort of cast to `void*` but that is standard practice in C.

## API

Note that `VECTOR` is any pointer type and that the API is mostly implemented
using macros. The macros all take `VECTOR` argument, size and indexing
arguments are expected to be `size_t`. The macros which push back a value
expect the pointer's base type.

##### vector_try_grow(VECTOR, MORE)
Attempts to grow `VECTOR` by `MORE`

##### vector_meta(VECTOR)
Get the metadata block for `VECTOR`

##### vector_free(VECTOR)
Deletes `VECTOR` and sets it to `NULL`

##### vector_push(VECTOR, VALUE)
Pushes back `VALUE` into `VECTOR`

##### vector_size(VECTOR)
Get the size of `VECTOR`

##### vector_capacity(VECTOR)
Get the capacity of `VECTOR`

##### vector_resize(VECTOR, SIZE)
Resize `VECTOR` to accomodate `SIZE` more elements

##### vector_last(VECTOR)
Get the last element in `VECTOR`

##### vector_pop(VECTOR)
Pop an element off the back of `VECTOR`

##### vector_shrinkto(VECTOR, SIZE)
Shrink the size of `VECTOR` down to `SIZE`

##### vector_shrinkby(VECTOR, AMOUNT)
Shrink `VECTOR` down by `AMOUNT`

##### vector_append(VECTOR, COUNT, POINTER)
Append to `VECTOR`, `COUNT` elements from `POINTER`

##### vector_remove(VECTOR, INDEX, COUNT)
Remove from `VECTOR`, `COUNT` elements starting from `INDEX`
