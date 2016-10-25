#include "../../stdio_common.h"

void runSuccess() {
    char s1[] = "old";
    char s2[] = "new";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    rename(s1, s2);
}

void runFailure() {
    char s2[] = "new";
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    rename(NULL, s2);
}

void runFailure1() {
    char s1[] = "old";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    rename(s1, NULL);
}

void runFailure2() {
    rename(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    char s1[] = "old";
    char s2[] = "new";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    result = rename(s1, s2);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
