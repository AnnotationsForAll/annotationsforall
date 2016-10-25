#include "../../../stdio_common.h"
#include <wchar.h>

/*@
assigns \result;
*/
extern wchar_t anychar();

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        putwc(anychar(), file);
    }
}

void runFailure() {
    putwc(anychar(), NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = putwc(anychar(), file);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
