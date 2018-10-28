//
// Created by Wang, Chen on 10/28/18.
//
#include <stdio.h>
#include "combine.h"

void combine1(vec_ptr v, data_t *dest) {
    long int i;
    *dest = IDENT;
    for (i = 0; i < vec_length(v); i++) {
        data_t val;
        val = get_vec_element(v, i, &val);
        long *valAddress = (long *) val;
        *dest = *dest OP *valAddress;
    }
}

int main() {
    vec_ptr vector = new_vec(10);
    long value = 0;
    for (int i = 0; i < 10; ++i)
        set_vec_element(vector, i, 2);
    data_t *data = &(value);
    combine1(vector, data);
    printf("%ld", (long) *data);
    return 0;
}