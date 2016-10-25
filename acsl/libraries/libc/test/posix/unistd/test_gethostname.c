#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    char buf[10];
    gethostname(buf, 10);
}

void runFailure() {
    gethostname(NULL, 10);
}

void runFailure1() {
    char buf[10];
    gethostname(buf, 20);
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[10];
    
    result = gethostname(buf, 10);
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
