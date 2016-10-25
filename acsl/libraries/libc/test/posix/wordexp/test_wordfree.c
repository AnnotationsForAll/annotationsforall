#include "../../../test_common.h"
#include <wordexp.h>

void runSuccess() {
    wordexp_t word;
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    if (wordexp(buf, &word, anyint())) {return;}

    wordfree(&word);
}

void runFailure() {
    wordfree(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    wordexp_t word;
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    if (wordexp(buf, &word, anyint())) {return;}

    wordfree(&word);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
