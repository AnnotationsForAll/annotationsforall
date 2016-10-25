#include "../../../test_common.h"
#include <malloc.h>

void runSuccess() {
    malloc_usable_size(anystring());
}

void runSuccess1() {
    malloc_usable_size(NULL);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    char* buf = malloc(10);
    int result = malloc_usable_size(buf);
    //@ assert result != 0 ==> result == 10;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
