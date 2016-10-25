#include "../../../test_common.h"
#include <sys/statvfs.h>

void runSuccess() {
    struct statvfs buf;
    
    fstatvfs(anyint(), &buf);
}

void runFailure() {
    statvfs(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    struct statvfs buf;
    
    result = fstatvfs(anyint(), &buf);
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
