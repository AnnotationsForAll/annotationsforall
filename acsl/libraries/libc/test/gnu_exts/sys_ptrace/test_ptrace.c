#include "../../../test_common.h"
#include <sys/ptrace.h>

void runSuccess() {
    void *a, *b;
    ptrace(anyint(), anyint(), a, b);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    void *a, *b;
    ptrace(anyint(), anyint(), a, b);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
