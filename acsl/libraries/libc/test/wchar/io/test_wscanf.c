#include "../../../stdio_common.h"
#include <wchar.h>

void runSuccess() {
    int input;
    wchar_t buf[4]; buf[0] = L'A'; buf[1] = L'A'; buf[2] = L'A'; buf[3] = L'\0';
    //@ assert \valid(buf+(0..3));
    //@ assert \exists integer x; buf[x] == L'\0';
    
    wscanf(buf, &input);
}

void runFailure() {
    wscanf(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    int input;
    wchar_t buf[4]; buf[0] = L'A'; buf[1] = L'A'; buf[2] = L'A'; buf[3] = L'\0';
    //@ assert \valid(buf+(0..3));
    //@ assert \exists integer x; buf[x] == L'\0';
    
    wscanf(buf, &input);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
