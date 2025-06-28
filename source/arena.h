#ifndef ARENA
#define ARENA

#include <stddef.h>

//#include "./genome.h"
#define CELL_IMPLEMENTATION
#include "./cell.h"
//#include "./stack.h"

struct arena {
        size_t length;
        struct genome* genomes;
        struct cell* cells;
};

extern struct arena *
arena_allocate(size_t const length);

extern void
arena_set(struct stack *restrict stack, struct arena *restrict arena,
          size_t const pid, size_t const id, size_t const genome_index,
          size_t const reserves, size_t const biomass);

extern inline struct cell *
arena_get_cell(struct arena *restrict arena, size_t const index);

extern inline struct genome *
arena_get_genome(struct arena *restrict arena, size_t const index);

extern void
arena_release(struct arena *restrict arena);
#endif //ARENA

#ifdef ARENA_IMPLEMENTATION

#include <stdlib.h>

extern struct arena *
arena_allocate(size_t const length) {
        struct arena *a = (struct arena*)malloc(sizeof(struct arena));
        a->length = length;
        a->genomes = (struct genome*)calloc(length, sizeof(struct genome));
        a->cells = (struct cell*)calloc(length, sizeof(struct cell));
        return a;
}

extern void
arena_set(struct stack *restrict stack, struct arena *restrict arena,
          size_t const pid, size_t const id, size_t const genome_index,
          size_t const reserves, size_t const biomass) {

        size_t index = stack_pop(stack);

        arena->genomes[index] = genome_generate();
        arena->cells[index] = cell_generate(pid, id, genome_index, reserves, 
                        biomass);
}

extern inline struct cell *
arena_get_cell(struct arena *restrict arena, size_t const index) {
        return &arena->cells[index];
}

extern inline struct genome *
arena_get_genome(struct arena *restrict arena, size_t const index) {
        return &arena->genomes[index];
}

extern void
arena_release(struct arena *restrict arena) {
        free(arena->genomes);
        free(arena->cells);
        free(arena);
}

#endif //ARENA_IMPLEMENTATION
