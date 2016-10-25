#include "../../../stdio_common.h"
#include <wchar.h>

/*@
assigns \result;
*/
extern wchar_t anychar();

void runSuccess() {
    putwchar(anychar());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    putwchar(anychar());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
