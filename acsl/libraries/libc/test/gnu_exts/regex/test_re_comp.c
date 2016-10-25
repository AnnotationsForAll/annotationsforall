#include "../../../stdio_common.h"
#include <regex.h>

void runSuccess() {
    re_comp(anystring());
}

void runSuccess1() {
    re_comp(NULL);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    char* result = re_comp(anystring());
    //@ assert result == \null || \valid_read(result);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
