#include "../../../stdio_common.h"

void runSuccess() {
   char s[10];
   char *sp = s;
   size_t sz = 10;
   
   open_memstream(&sp, &sz);
}

void runFailure() {
    size_t sz = 10;

    open_memstream(NULL, &sz);
}

void runFailure1() {
    char s[10];

    open_memstream(&s, NULL);
}

void runFailure2() {
    char s[10];
    size_t sz = 20;

    open_memstream(&s, &sz);
}

int f;
void testValues() {
    f = 2;
    FILE* result;
    char s[10];
    size_t sz = 10;
    
    result = open_memstream(&s, &sz);
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
