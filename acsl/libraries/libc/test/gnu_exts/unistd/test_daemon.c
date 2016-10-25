#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    daemon(anyint(), anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    daemon(anyint(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
