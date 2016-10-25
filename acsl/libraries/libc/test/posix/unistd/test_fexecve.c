#include "../../../test_common.h"
#include <fcntl.h>

void runSuccess() {
    char* argv[1];
    argv[0] = NULL;
    
    char* arge[1];
    arge[0] = NULL;
    
    execve(anyint(), argv, arge);
}

void runFailure() {
    execve(anyint(), NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    char* argv[1];
    argv[0] = NULL;
    
    char* arge[1];
    arge[0] = NULL;
    
    execve(anyint(), argv, arge);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
