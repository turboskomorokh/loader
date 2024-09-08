#include <stdint.h>

#pragma once

typedef void (*__func_entry)(void);

extern uint64_t __func_load_abs_layer;
extern void* __func_load_return_value;

#define __FUNC_LOAD_MAX_ITER 127

void __func_load(__func_entry);