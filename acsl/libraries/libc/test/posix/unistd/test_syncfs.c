#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    syncfs(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;

    syncfs(anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
