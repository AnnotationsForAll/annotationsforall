#include "../../../test_common.h"
#include <langinfo.h>

/*@
assigns \result;
*/
extern nl_item anyitem();

void runSuccess() {
    nl_langinfo(CODESET);
    nl_langinfo(MON_3);
    nl_langinfo(anyitem());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    result = nl_langinfo(ERA);
    //@ assert \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
