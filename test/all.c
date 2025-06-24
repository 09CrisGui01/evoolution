#include <stdio.h>
#define TEST_ALL
#include "test.h"

#include "stack.c"

int main() {
        test_stack();
        show_results(stderr);
        return 0;
}
