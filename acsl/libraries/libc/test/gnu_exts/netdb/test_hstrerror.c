#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    hstrerror(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    char* result = hstrerror(anyint());
    //@ assert \valid_read(result);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
