#include "../../../test_common.h"
#include <sys/sem.h>

void runSuccess() {
    semctl(anyint(), anyint(), anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    semctl(anyint(), anyint(), anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
