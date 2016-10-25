#include "../../stdio_common.h"

void runSuccess() {
    char buf[L_tmpnam];
    
    tmpnam(buf);
    tmpnam(NULL);
}

void runFailure() {
    char buf[1];
    
    tmpnam(buf); //buffer provided too short
}

int f;
void testValues() {
    f = 2;
    char* result;
    char buf[L_tmpnam];
    
    result = tmpnam(buf);
    //@ assert result == buf || result == \null;
    result = tmpnam(NULL);
    //@ assert result != \null ==> \valid(result+(0..( L_tmpnam )-1));

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
