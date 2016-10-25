#include "../../../test_common.h"
#include <sys/stat.h>

void runSuccess() {
    struct stat buf;
    
    fstat(anyint(), &buf);
}

void runFailure() {
    fstat(anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    struct stat buf;
    
    result = fstat(anyint(), &buf);
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
