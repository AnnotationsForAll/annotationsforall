#include "../../test_common.h"
#include <time.h>

time_t ptr;

void runSuccess() {
    time(&ptr);
    time(NULL);
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    time_t result;
    
    result = time(&ptr);
    //@ assert ptr == result;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}