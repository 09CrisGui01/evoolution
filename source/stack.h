#ifndef STACK_H
#define STACK_H

#include <limits.h>
#include <stdint.h>
#include <stddef.h>

#ifndef STACK_MAX
#define STACK_MAX (1000)
#endif //STACK_MAX

struct stack {
        size_t values[STACK_MAX];
        size_t top;
};

extern inline void
stack_initialise(struct stack *restrict stack);

extern inline void
stack_push(struct stack *restrict stack, size_t const index);

extern inline size_t const
stack_pop(struct stack *restrict stack);

extern inline size_t const
stack_peek(struct stack *const restrict stack);

extern inline bool
stack_is_full(struct stack *const restrict stack);

extern inline bool
stack_is_empty(struct stack *const restrict stack);

#endif //STACK_H

#ifdef STACK_IMPLEMENTATION

extern inline void
stack_initialise(struct stack *restrict stack) {
       stack->top = -1;
}

extern inline void
stack_push(struct stack *restrict stack, size_t const index) {
        if(stack_is_full(stack)) return (void)0;
        stack->values[++stack->top] = index;
}

extern inline size_t const
stack_pop(struct stack *restrict stack) {
        if(stack_is_empty(stack)) return INT_MIN;
        return stack->values[stack->top--];
}

extern inline size_t const
stack_peek(struct stack *const restrict stack) {
        return stack->values[stack->top];
}

extern inline bool
stack_is_full(struct stack *const restrict stack) {
        return STACK_MAX == stack->top;
}

extern inline bool
stack_is_empty(struct stack *const restrict stack) {
       return -1 == (int)stack->top;
}

#endif //STACK_IMPLEMENTATION
