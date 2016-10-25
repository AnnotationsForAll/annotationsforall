#ifndef TESTS_UNISTD_COMMON_H_
#define TESTS_UNISTD_COMMON_H_

#include "test_common.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

/*@
assigns \result \from \nothing;
ensures \valid(\result+(0..0));
ensures \result[0] == '\0';
*/
extern char* _validpath();

//this ensures that you have a valid file descriptor. Be sure to still check if VALID_FILE is -1, though!
#define VALID_FD open(_validpath(), anyint())

/*@
assigns \result \from \nothing;
ensures \valid(\result+(0..0));
ensures \result[0] == '\0';
*/
extern char* _validpname();

/*@
assigns \result \from \nothing;
ensures \valid(\result+(0..1));
ensures \result[0] == 'r';
ensures \result[1] == '\0';
*/
extern char* _validpopt();

//this ensures that you have a valid FILE*. Be sure to still check if VALID_FILE is null, though!
#define VALID_PIPEFILE fopen(_validpname(), _validpopt())

//returns a valid PID. getpid() never fails, so there's no need to check.
#define VALID_PID getpid()

#endif
