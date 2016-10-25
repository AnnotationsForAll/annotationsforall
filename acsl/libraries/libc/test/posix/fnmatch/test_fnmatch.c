#include "../../../test_common.h"
#include <fnmatch.h>

void runSuccess() {
    char s1[] = "p1";
    char s2[] = "p2";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    fnmatch(s1, s2, anyint());
}

void runFailure() {
    fnmatch(NULL, NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    char s1[] = "p1";
    char s2[] = "p2";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    fnmatch(s1, s2, anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
