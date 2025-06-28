#include <stddef.h>
#include <stdint.h>

#include "test.h"

#define GENOME_IMPLEMENTATION
#include "../source/genome.h"

int8_t
test_genome_generate() {
        struct genome g = genome_generate();
        //if(!g) return -1;
        if(g.mutation_rate < 0) return -2;
        if(sizeof(g.DNA) != sizeof(uint8_t)*GEN_LENGTH*GEN_QUANTITY) return -3;
        return 0;
}

//[[deprecated("Use test_genome_generate() instead.")]]
//int8_t
//test_genome_initialise() {
//        struct genome g;
//        //genome_initialise(&g);
//        //if(nullptr == g) return -1;
//
//        return 0;
//}

int8_t
test_genome_fprintf() {
        struct genome g;
        //genome_initialise(&g);
        genome_fprintf(stdout, &g);
        return 0;
}

void
test_genome() {
        test_func(stderr, test_genome_generate);
        //test_func(stderr, test_genome_initialise);
        test_func(stderr, test_genome_fprintf);
}
