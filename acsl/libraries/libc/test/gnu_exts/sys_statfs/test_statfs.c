#include "../../../test_common.h"
#include <sys/statfs.h>

void runSuccess() {
    struct statfs buf;
    char path[] = "name";
    //@ assert \valid(path+(0..\block_length(path)-1));
    //@ assert \exists integer x; path[x] == '\0';
    
    statfs(path, &buf);
}

void runFailure() {
    statfs(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    struct statfs buf;
    char path[] = "name";
    //@ assert \valid(path+(0..\block_length(path)-1));
    //@ assert \exists integer x; path[x] == '\0';
    
    result = statfs(path, &buf);
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
