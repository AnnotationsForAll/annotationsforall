#include "../../../test_common.h"
#include <dirent.h>
#include <errno.h>

void runSuccess() {
    char dir[] = ".";
    //@ assert \valid(dir+(0..\block_length(dir)-1));
    //@ assert \exists integer x; dir[x] == '\0';
    
    opendir(dir);
}

void runFailure() {
    opendir(NULL);
}

int f;
void testValues() {
    f = 2;
    DIR* result;
    
    char dir[] = ".";
    //@ assert \valid(dir+(0..\block_length(dir)-1));
    //@ assert \exists integer x; dir[x] == '\0';
    
    result = opendir(dir);
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
