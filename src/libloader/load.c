#include <stdint.h>
#include <stdio.h>
#include "loader.h"

void *__func_load_return_value;
uint64_t __func_load_abs_layer = 0;

void __func_load(__func_entry ptr) {
    __func_load_abs_layer += 1;

    if (__func_load_abs_layer >= __FUNC_LOAD_MAX_ITER) {
        printf("__func_load: reached __func_load_abs_layer limit of %lu\n", __func_load_abs_layer);
        __func_load_abs_layer -= 1;
        return;
    }

    asm volatile(
        "call *%1          \n\t"
        "movq %%rax, %0    \n\t"
        : "=r"(__func_load_return_value)
        : "r"(ptr)
        : "rax"
    );

    __func_load_abs_layer -= 1;
    printf("Return code: %lu\n", (unsigned long)(uintptr_t)__func_load_return_value);
}
