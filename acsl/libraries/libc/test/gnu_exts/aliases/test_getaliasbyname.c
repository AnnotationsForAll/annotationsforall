#include "../../../test_common.h"
#include <aliases.h>

void runSuccess() {
    getaliasbyname(anystring());
}

void runFailure() {
    getaliasbyname(NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct aliasent * result = getaliasbyname(anystring());
    //@ assert result != \null ==> \valid_read(result->alias_name);
    //@ assert result != \null ==> result->alias_members_len > 0 ==> \valid_read(result->alias_members[0]);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
