#include "../../../stdio_common.h"
#include <wchar.h>

void runSuccess() {
    wchar_t buf[10];
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fgetws(buf, 5, file);
    }
}

void runSuccess1() {
    wchar_t buf[10];
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fgetws(buf, 10, file);
    }
}

void runFailure() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fgetws(NULL, 5, file);
    }
}

void runFailure1() {
    wchar_t buf[10];
    
    fgetws(buf, 10, NULL);
}

void runFailure2() {
    wchar_t buf[10];
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fgetws(buf, 20, file);
    }
}

int f;
void testValues() {
    f = 2;
    wchar_t* result;
    wchar_t buf[10];
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = fgetws(buf, 10, file);
        //@ assert result == \null || result == buf;
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
