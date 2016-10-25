#include "../../../unistd_common.h"

void runSuccess() {
    FILE* file = VALID_PIPEFILE;
    if (file != NULL) {
        pclose(file);
    }
}

void runFailure() {
    pclose(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    FILE* file = VALID_PIPEFILE;
    
    if (file != NULL) {
        result = pclose(file);
        //@ assert result != -1 ==> !\valid(file);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
