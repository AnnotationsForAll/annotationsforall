#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
   char buf[256];
   initstate(anyuint(), buf, 256);
}

void runSuccess1() {
   char buf[256];
   initstate(anyuint(), buf, 16);
}

void runFailure1() {
    char buf[256];
    initstate(anyuint(), NULL, 256);
}

int f;
void testValues() {
    f = 2;
    char* result;
    char buf[256];
    
    result = initstate(anyuint(), buf, 256);
    //@ assert result == \null || result == buf;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
