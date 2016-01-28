/*********************************************\
* Note that while twbctf is Licensed GPLv2,   *
* this file is Public Domain; You may license *
* your own tests.c as you wish                *
\*********************************************/

#include "twbctf.h" // Don't remove this!

declare_test(test_success) {
    return 0;
}

declare_test(test_failure) {
    return 1;
}

const struct test test_list [] = {
    { "successful test", test_success },
    { "failing test",    test_failure }
};

