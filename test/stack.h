#include <stdint.h>

#include "test.h"

#define STACK_IMPLEMENTATION
#include "../source/stack.h"

int8_t
test_stack_initialise() {
        struct stack s;
        size_t top = -1;//s.top;
        stack_initialise(&s);

        if(top != s.top) return -1;
        return 0;
}

int8_t
test_stack_push() {
        struct stack s;
        stack_initialise(&s);

        stack_push(&s, INT8_MAX);
        stack_push(&s, INT8_MIN);

        if(1 != s.top) return -1;
        if(INT8_MIN != (int)s.values[s.top]) return -2;
        return 0;
}

int8_t
test_stack_pop() {
        struct stack s;
        stack_initialise(&s);

        stack_push(&s, INT8_MAX);
        stack_push(&s, INT8_MIN);

        if(INT8_MIN != (int)stack_pop(&s)) return -1;
        if(0 != s.top) return -2;
        if(INT8_MAX != s.values[s.top]) return -3;
        return 0;
}

int8_t
test_stack_peek() {
        struct stack s;
        stack_initialise(&s);

        stack_push(&s, INT8_MAX);
        stack_push(&s, INT8_MIN);

        if(INT8_MIN != (int)stack_peek(&s)) return -1;
        stack_pop(&s);
        if(INT8_MAX != (int)stack_peek(&s)) return -2;
        return 0;
}

int8_t
test_stack_is_full() {
        struct stack s;
        stack_initialise(&s);

        if(false != stack_is_full(&s)) return -1;

        stack_push(&s, 123);
        if(false != stack_is_full(&s)) return -2;

        for(size_t i=0; i<STACK_MAX+1; ++i)
                stack_push(&s, i);

        if(true != stack_is_full(&s)) return -3;
        return 0;
}

int8_t
test_stack_is_empty() {
        struct stack s;
        stack_initialise(&s);

        if(true != stack_is_empty(&s)) return -1;

        stack_push(&s, 123);
        if(false != stack_is_empty(&s)) return -2;

        for(size_t i=0; i<STACK_MAX+1; ++i) {
                stack_push(&s, i);
        }

        if(false != stack_is_empty(&s)) return -3;
        return 0;
}

void
test_stack() {
        test_func(stderr, test_stack_initialise);
        test_func(stderr, test_stack_push);
        test_func(stderr, test_stack_pop);
        test_func(stderr, test_stack_peek);
        test_func(stderr, test_stack_is_full);
        test_func(stderr, test_stack_is_empty);
}
