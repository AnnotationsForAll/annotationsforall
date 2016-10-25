#include "../../../test_common.h"
#include <locale.h>

/*@
assigns \result;
*/
extern locale_t locale();

void runSuccess() {
    duplocale(locale());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    locale_t result;
    
    result = duplocale(locale());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
