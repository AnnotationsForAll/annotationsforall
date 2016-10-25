#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    int fd = 1; // placeholder
    close(fd);
}

void runFailure() {
    close(anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    int fd = 1; // placeholder
    
    result = close(fd);
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
