#ifndef TEST_H
#define TEST_H

#include <stdint.h>
#include <stdio.h>

static int8_t count_error = 0;
static int8_t count_warning = 0;
static int8_t count_success = 0;

#define show_results(stream)                                            \
do {                                                                    \
        fprintf(stream, "Total: %d\tSuccess: %d\tWarning: %d\tError: %d\n", (count_success + count_warning + count_error), count_success,  count_warning, count_error);                                    \
} while (false)

#define test_func(stream, func, ...)                            \
do {                                                            \
        int8_t r = func(__VA_ARGS__);                           \
        if(r < 0) {                                             \
                fprintf(stream, "ERROR:\t\t %s( ", #func);      \
                fprintf(stream, "%s", ##__VA_ARGS__);           \
                fprintf(stream, " ) \t-> %d\n", r);               \
                ++count_error;                                  \
        }                                                       \
        else if(r > 0) {                                        \
                fprintf(stream, "WARNING:\t %s( ", #func);      \
                fprintf(stream, "%s", ##__VA_ARGS__);           \
                fprintf(stream, " ) \t-> %d\n", r);               \
                ++count_warning;                                \
        }                                                       \
        else {                                                  \
                fprintf(stream, "SUCCESS:\t %s( ", #func);                                         \
                fprintf(stream, "%s", ##__VA_ARGS__);           \
                fprintf(stream, " ) \t-> %d\n", r);               \
                ++count_success;                                \
        }                                                       \
} while(false)

#endif //TEST_H
