#include "../../../test_common.h"
#include <sys/statfs.h>

void runSuccess() {
    struct statfs buf;
    
    fstatfs(anyint(), &buf);
}

void runFailure() {
    fstatfs(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    struct statfs buf;
    
    result = fstatfs(anyint(), &buf);
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
