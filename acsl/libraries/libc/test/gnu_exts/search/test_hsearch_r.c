#include "../../../test_common.h"
#include <search.h>

/*@
assigns \result;
*/
extern ENTRY anyentry();

void runSuccess() {
    struct hsearch_data htab;
    if (!hcreate_r(anysize(), &htab)) {return;}

    ENTRY* ret;
    hsearch_r(anyentry(), FIND, &ret, &htab);
    hsearch_r(anyentry(), ENTER, &ret, &htab);
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;

    struct hsearch_data htab;
    if (!hcreate_r(anysize(), &htab)) {return;}
    
    ENTRY* ret;
    hsearch_r(anyentry(), FIND, &ret, &htab);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
