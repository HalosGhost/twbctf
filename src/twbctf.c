/*******************************************************************\
* A small, native C test suite for libweather                       *
* Copyright (C) 2013-2014, Sam Stuewe                               *
*                                                                   *
* This program is free software; you can redistribute it and/or     *
* modify it under the terms of the GNU General Public License       *
* as published by the Free Software Foundation; either version 2    *
* of the License, or (at your option) any later version.            *
*                                                                   *
* This program is distributed in the hope that it will be useful,   *
* but WITHOUT ANY WARRANTY; without even the implied warranty of    *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the      *
* GNU General Public License for more details.                      *
*                                                                   *
* You should have received a copy of the GNU General Public License *
* along with this program; if not, write to the Free Software       *
* Foundation, Inc., 51 Franklin Street, Fifth Floor,                *
* Boston, MA  02110-1301, USA.                                      *
\*******************************************************************/

// Libraries //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "twbctf.h"

// Forward Declarations //
#define TEST_COUNT ((sizeof test_list)/(sizeof test_list[0]))

/* Test Utilities */
void 
run_test (char * test_name, test_p function);

// Run Suite //
int 
main (void) {

    for ( size_t i = 0; i < TEST_COUNT; i ++ ) {
        run_test(test_list[i].desc, test_list[i].func);
    } return 0;
}

void 
run_test (char * test_name, test_p func) {

    printf("Testing %s\t\t[ PEND ]\r", test_name);
    char * test_result = (func() ? "\x1b[32mPASS" : "\x1b[31mFAIL");
    printf("Testing %s\t\t[ %s \x1b[0m]\n", test_name, test_result);
}
// vim: set ts=4 sw=4 et:
