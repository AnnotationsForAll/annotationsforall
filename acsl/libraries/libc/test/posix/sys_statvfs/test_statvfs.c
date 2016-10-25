#include "../../../test_common.h"
#include <sys/statvfs.h>

void runSuccess() {
    struct statvfs buf;
    char path[] = "name";
    //@ assert \valid(path+(0..\block_length(path)-1));
    //@ assert \exists integer x; path[x] == '\0';
    
    statvfs(path, &buf);
}

void runFailure() {
    statvfs(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    struct statvfs buf;
    char path[] = "name";
    //@ assert \valid(path+(0..\block_length(path)-1));
    //@ assert \exists integer x; path[x] == '\0';
    
    result = statvfs(path, &buf);
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
