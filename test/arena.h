#include <stdio.h>
#include <stdint.h>

#include "test.h"

#define ARENA_IMPLEMENTATION
#include "../source/arena.h"

//#define CELL_IMPLEMENTATION
//#include "../source/cell.h"

int8_t
test_arena_allocate() {
        struct arena *a = arena_allocate(1024);
        if(nullptr == a) return -1;
        if(!a) return -2;
        if(nullptr == a->cells) return -3;
        if(nullptr == a->genomes) return -4;
        if(0 >= a->length) return -5;
        return 0;
}

void
test_arena() {
        test_func(stderr, test_arena_allocate);
}
