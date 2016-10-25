#include "../../../stdio_common.h"
#include <wchar.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern FILE* anyfile();
int input;

void runSuccess() {
    wchar_t buf[4]; buf[0] = L'A'; buf[1] = L'A'; buf[2] = L'A'; buf[3] = L'\0';
    //@ assert \valid(buf+(0..3));
    //@ assert \exists integer x; buf[x] == L'\0';
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fwscanf(file, buf, &input);
    }
}

void runFailure() {
    wchar_t buf[4]; buf[0] = L'A'; buf[1] = L'A'; buf[2] = L'A'; buf[3] = L'\0';
    //@ assert \valid(buf+(0..3));
    //@ assert \exists integer x; buf[x] == L'\0';
    
    fwscanf(NULL, buf, &input);
}

void runFailure1() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fwscanf(file, NULL);
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
        fwscanf(file, buf, &input);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
