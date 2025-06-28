//#include <stdio.h>
#include "test.h"

#include "./genome.h"
#include "./stack.h"
#include "./arena.h"


int main() {
        test_genome();
        test_stack();
        test_arena();

        show_results(stderr);
        return 0;
}
