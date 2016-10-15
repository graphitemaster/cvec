#include "cvec.h"

void vec_grow(void **vector, size_t more, size_t type_size) {
    vector_t *meta = vector_meta(*vector);
    size_t count = 0;
    void *data = NULL;

    if (*vector) {
        count = 2 * meta->allocated + more;
        data = realloc(meta, type_size * count + sizeof *meta);
    } else {
        count = more + 1;
        data = malloc(type_size * count + sizeof *meta);
        ((vector_t *)data)->used = 0;
    }

    meta = (vector_t *)data;
    meta->allocated = count;
    *vector = meta + 1;
}

void vec_delete(void *vector) {
    free(vector_meta(vector));
}
