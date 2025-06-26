#ifndef CELL
#define CELL

#include <stddef.h>

struct Cell {
        size_t pid; //Parent ID
        size_t id;
        size_t genome_index;
        size_t reserves;
        size_t biomass;
};

#endif //CELL

#ifdef CELL_IMPLEMENTATION



#endif //CELL_IMPLEMENTATION
