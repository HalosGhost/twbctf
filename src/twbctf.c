/*******************************************************************\
* A small, C test framework                                         *
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
#include <stdint.h>  // explicitly sized types
#include <stdio.h>   // printf(), putchar()
#include <string.h>  // strlen()
#include "twbctf.h"  // testing forward declarations
#include "tests.c"   // tests

// Run Suite //
int32_t
main (int32_t argc, char * argv []) {

    const size_t TC = (sizeof test_list)/(sizeof (struct test));
    bool results [TC], ret = false;
    uint16_t maxl = 0;

    for ( size_t i = 0; i < TC; i ++ ) {
        uint16_t cur = (uint16_t )strlen(test_list[i].desc);
        maxl = cur > maxl ? cur : maxl;
    }

    if ( argc > 1 && *(int16_t * )argv[1] == *(int16_t * )"-s" ) { // shortened
        for ( size_t i = 0; i < TC; i ++ ) {
            results[i] = test_list[i].func();
            putchar(results[i] ? '.' : '!');
            ret = ret || !results[i];
        } if ( ret ) {
            printf("\x1b[0m\n\nFailed Tests:\n");
            for ( size_t i = 0; i < TC; i ++ ) {
                !results[i] ? printf(" %s\n", test_list[i].desc) : printf("");
            }
        }
    } else {
        for ( size_t i = 0; i < TC; i ++ ) {
            printf("Testing %-*s\t[ PEND ]\r", maxl, test_list[i].desc);
            bool result = test_list[i].func();
            const char * r = result ? "\x1b[32mPASS" : "\x1b[31mFAIL";
            printf("Testing %-*s\t[ %s \x1b[0m]\n", maxl, test_list[i].desc, r);
            ret = ret || !result;
        }
    } return ret;
}

// vim: set ts=4 sw=4 et:
