#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    syscall(anylongint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    


    //@ assert f == 2;
    //@ assert vacuous: \false;
}
