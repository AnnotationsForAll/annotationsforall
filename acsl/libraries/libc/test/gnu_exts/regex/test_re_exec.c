#include "../../../stdio_common.h"
#include <regex.h>

void runSuccess() {
    re_exec(anystring());
}

void runFailure() {
    re_exec(NULL);
}

int f;
void testValues() {
    f = 2;
    
    int result = re_exec(anystring());
    //@ assert result == -1 || result == 0 || result == 1;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
