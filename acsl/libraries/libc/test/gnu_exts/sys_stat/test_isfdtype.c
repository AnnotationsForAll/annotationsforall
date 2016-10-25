#include "../../../test_common.h"
#include <sys/stat.h>

void runSuccess() {
    isfdtype(anyint(), anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    isfdtype(anyint(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
