#include "../../../unistd_common.h"
#include <time.h>

void runSuccess() {
    tzset();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    tzset();
    //@ assert \valid(tzname[0]) && \valid(tzname[1]);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
