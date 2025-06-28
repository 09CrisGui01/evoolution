//#include <stdio.h>
#include "test.h"

#include "./genome.h"
#include "./stack.h"


int main() {
        test_stack();
        test_genome();
        show_results(stderr);
        return 0;
}
