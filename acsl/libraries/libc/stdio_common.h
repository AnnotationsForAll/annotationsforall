//If you include this, there is no need to include stdio or test_common.

#ifndef TESTS_STDIO_COMMON_H_
#define TESTS_STDIO_COMMON_H_

#include "test_common.h"
#include <stdio.h>

/*@
assigns \result \from \nothing;
ensures \valid(\result+(0..0));
ensures \result[0] == '\0';
*/
extern char* _validfname();

/*@
assigns \result \from \nothing;
ensures \valid(\result+(0..1));
ensures \result[0] == 'r';
ensures \result[1] == '\0';
*/
extern char* _validfopt();

//this ensures that you have a valid FILE*. Be sure to still check if VALID_FILE is null, though!
#define VALID_FILE fopen(_validfname(), _validfopt())

#endif
