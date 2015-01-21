/*********************************************\
* Note that while twbctf is Licensed GPLv2,   *
* this file is Public Domain; You may license *
* your own tests.c as you wish                *
\*********************************************/

#include "twbctf.h" // Don't remove this!

bool test_success (void);
bool test_fail    (void);

const struct test test_list [] = {
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

