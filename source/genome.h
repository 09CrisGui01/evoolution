#ifndef GENOME
#define GENOME

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef GEN_LENGTH
#define GEN_LENGTH 16
#endif

#ifndef GEN_QUANTITY
#define GEN_QUANTITY 8
#endif

struct genome {
        uint8_t DNA[GEN_LENGTH*GEN_QUANTITY];
        float mutation_rate;
};

struct genome
genome_generate();

[[deprecated("Use genome_generate() instead.")]] 
void
genome_initialise(struct genome *const restrict genome);

void 
genome_fprintf(FILE *stream, struct genome *const restrict genome);

#endif //GENOME

#ifdef GENOME_IMPLEMENTATION
#define genome_at(row, column) (row*GEN_QUANTITY+column)

void genome_initialise(struct genome *restrict genome) {
      for(size_t i=0; i<GEN_QUANTITY; ++i) {
        for(size_t j=0; j<GEN_LENGTH; ++j) {
                genome->DNA[genome_at(i,j)] = rand() % 256;
        }
      }
      genome->mutation_rate = ((float)rand() / (float)(RAND_MAX)) * 100.0;
}

void genome_fprintf(FILE *stream, struct genome *const restrict genome) {
      for(size_t i=0; i<GEN_QUANTITY; ++i) {
        for(size_t j=0; j<GEN_LENGTH; ++j) {
                fprintf(stream, "%3d ", genome->DNA[genome_at(i,j)]);
        }
        fprintf(stream, "\n");
      }
}

struct genome
genome_generate() {
        struct genome g = {};
        g.mutation_rate = (float)rand();
        for(size_t i=0; i<GEN_LENGTH*GEN_QUANTITY; ++i) {
                g.DNA[i] = (uint8_t)(rand() % 256);
        }
        return g;
}

#endif //GENOME_IMPLEMENTATION
