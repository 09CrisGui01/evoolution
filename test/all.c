//#include <stdio.h>
#include "test.h"

#include "./stack.h"

#include "./genome.h"

int main() {
        test_stack();
        test_genome();
        show_results(stderr);
        return 0;
}
