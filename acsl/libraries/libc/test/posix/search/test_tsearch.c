#include "../../../test_common.h"
#include <search.h>
#include <string.h>

void runSuccess() {
    char key[5];
    void* tree = NULL;
    
    tsearch(key, &tree, strcmp);
}

void runFailure() {
    char key[5];
    void* tree = NULL;
    
    tsearch(key, &tree, NULL);
}

int f;
void testValues() {
    f = 2;
    void* result;
    
    char key[5];
    void* tree = NULL;
    
    result = tsearch(key, &tree, strcmp);
    //@ assert result == \null || \valid((char*)result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
