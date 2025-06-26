#include <stdint.h>

#include "test.h"
//#include "../source/genome.h"
#define GENOME_IMPLEMENTATION
#include "../source/genome.h"

int8_t
test_genome_initialise() {
        struct genome g;
        genome_initialise(&g);
        //if(nullptr == g) return -1;

        return 0;
}

int8_t
test_genome_fprintf() {
        struct genome g;
        genome_initialise(&g);
        genome_fprintf(stdout, &g);
        return 0;
}

void
test_genome() {
        test_func(stderr, test_genome_initialise);
        test_func(stderr, test_genome_fprintf);
}
