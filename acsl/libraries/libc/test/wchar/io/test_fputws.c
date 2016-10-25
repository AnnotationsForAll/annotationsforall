#include "../../../stdio_common.h"
#include <wchar.h>

void runSuccess() {
    wchar_t buf[4]; buf[0] = L'A'; buf[1] = L'A'; buf[2] = L'A'; buf[3] = L'\0';
    //@ assert \valid(buf+(0..3));
    //@ assert \exists integer x; buf[x] == L'\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fputws(buf, file);
    }
}

void runFailure() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fputws(NULL, file);
    }
}

int f;
void testValues() {
    f = 2;
    int result;
    wchar_t buf[4]; buf[0] = L'A'; buf[1] = L'A'; buf[2] = L'A'; buf[3] = L'\0';
    //@ assert \valid(buf+(0..3));
    //@ assert \exists integer x; buf[x] == L'\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = fputws(buf, file);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
