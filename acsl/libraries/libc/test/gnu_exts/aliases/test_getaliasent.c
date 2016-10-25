#include "../../../test_common.h"
#include <aliases.h>

void runSuccess() {
    getaliasent();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    struct aliasent * result = getaliasent();
    //@ assert result != \null ==> \valid_read(result->alias_name);
    //@ assert result != \null ==> result->alias_members_len > 0 ==> \valid_read(result->alias_members[0]);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
