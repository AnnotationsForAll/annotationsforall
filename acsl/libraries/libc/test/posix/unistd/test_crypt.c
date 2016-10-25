#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    char s1[] = "s1";
    char s2[] = "s2";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    crypt(s1, s2);
}

void runFailure() {
    crypt(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    char* result;
    char s1[] = "s1";
    char s2[] = "s2";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    result = crypt(s1, s2);
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
