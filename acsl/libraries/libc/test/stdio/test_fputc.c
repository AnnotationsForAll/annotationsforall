#include "../../stdio_common.h"

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fputc(anyint(), file);
    }
}

void runFailure() {
    fputc(anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    int x = anyint();
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = fputc(x, file);
        //@ assert result == EOF || (unsigned char)x == result;
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
