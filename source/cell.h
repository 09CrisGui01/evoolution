#ifndef CELL
#define CELL

#include <stddef.h>

struct cell {
        size_t pid; //Parent ID
        size_t id;
        size_t genome_index;
        size_t reserves;
        size_t biomass;
};

inline struct cell
cell_generate(size_t const pid, size_t const id, size_t const genome_index,
              size_t const reserves, size_t const biomass);

#endif //CELL

#ifdef CELL_IMPLEMENTATION

inline struct cell
cell_generate(size_t const pid, size_t const id, size_t const genome_index,
              size_t const reserves, size_t const biomass) {
        return (struct cell){
                .pid = pid,
                .id = id,
                .genome_index = genome_index,
                .reserves = reserves,
                .biomass = biomass,
        };
}

#endif //CELL_IMPLEMENTATION
