#include "../../../test_common.h"
#include <search.h>

/*@
assigns \result;
*/
extern ENTRY anyentry();

void runSuccess() {
    if (!hcreate(anysize())) {return;}

    hsearch(anyentry(), FIND);
    hsearch(anyentry(), ENTER);
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    ENTRY* result;
    if (!hcreate(anysize())) {return;}
    
    result = hsearch(anyentry(), FIND);
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
