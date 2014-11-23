#ifndef __TWBCTF_H__
#define __TWBCTF_H__

// Libraries //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

typedef bool (* test_p) (void);

struct test {
    char * desc;
    test_p func;
};

extern struct test test_list [];

// Edit tests and struct below this line

bool test_success (void);
bool test_fail    (void);

struct test test_list [] = {
    { "success\t",   (test_p )test_success       },
    { "fail\t",      (test_p )test_fail          }
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
#endif // __TWBCTF_H__
