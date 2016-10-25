#include "../../../test_common.h"
#include <net/if.h>

void runSuccess() {
    if_nameindex();
}

void runFailure() {
    
}

void runFailure1() {
    
}

int f;
void testValues() {
    f = 2;
    struct if_nameindex * result;
    
    result = if_nameindex();
    //@ assert result == \null || \valid(result);
    //@ assert result != \null ==> \exists integer x; result[x].if_index == 0 && result[x].if_name == \null;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
