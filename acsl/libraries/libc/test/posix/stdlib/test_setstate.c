#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
   char buf[256];
   if (initstate(anyuint(), buf, 256) == NULL) {return;}
   
   setstate(buf);
}

void runSuccess1() {
   char buf[256];
   if (initstate(anyuint(), buf, 256) == NULL) {return;}
   
   setstate(buf);
}

void runFailure() {
    setstate(NULL);
}

int f;
void testValues() {
    f = 2;
    char* result;
    char buf[256];
    if (initstate(anyuint(), buf, 256) == NULL) {return;}
    
    result = setstate(buf);
    //@ assert result == \null || result == buf;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
