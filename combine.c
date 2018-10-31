//
// Created by Wang, Chen on 10/28/18.
//
#include <stdio.h>
#include "combine.h"

void combine1(vec_ptr v, data_t *dest) {
    long int i;
    *dest = IDENT;
    for (i = 0; i < vec_length(v); i++) {
        data_t *val;
        get_vec_element(v, i, &val);
        *dest = (*dest OP *val);
    }
}

int main() {
    vec_ptr vector = new_vec(10);
    for (int i = 0; i < 10; i++)
        set_vec_element(vector, i, 55);
    data_t val;
    combine1(vector, &val);
    printf("%ld", val);
    return 0;
}