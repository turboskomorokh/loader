#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>

#include "libloader/loader.h"

#include <stdint.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <library>\n", argv[0]);
        return 1;
    }

    void *binary = dlopen(argv[1], RTLD_NOW);
    if (!binary) {
        fprintf(stderr, "Error opening library: %s\n", dlerror());
        return 1;
    }

    __func_entry func = dlsym(binary, "main");

    __func_load(func);

    if (dlclose(binary) != 0) {
        fprintf(stderr, "Error closing library: %s\n", dlerror());
        return 1;
    }

    return 0;
}