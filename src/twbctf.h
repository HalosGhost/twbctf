#ifndef TWBCTF_H
#define TWBCTF_H

// Libraries //
#include <stdbool.h> // bool keyword
#include <stdint.h>  // explicitly sized types
#include <stdio.h>   // printf(), putchar()
#include <string.h>  // strlen()

typedef bool (* test_p) (void);

struct test {
    char * desc;
    test_p func;
};

extern struct test test_list [];

/**
 * If you need other libraries / headers, edit includes above
 * Edit tests and struct list below
 */

bool test_success (void);
bool test_fail    (void);

struct test test_list [] = {
    { "success", test_success },
    { "fail",    test_fail    }
};

bool
test_success (void) {
    return true;
}

bool
test_fail (void) {
    return false;
}

// vim: set ts=4 sw=4 et:
#endif // TWBCTF_H
