#include "../../stdio_common.h"

void runSuccess() {
    int input;
    char s1[] = "s1";
    char s2[] = "s2";
    
    sscanf(s1, s2, &input);
}

void runFailure() {
    int input;
    char s2[] = "s2";
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    sscanf(NULL, s2, &input);
}

void runFailure1() {
    char s1[] = "s1";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    sscanf(s1, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    int input;
    char s1[] = "s1";
    char s2[] = "s2";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    result = sscanf(s1, s2, &input);
    //@ assert result >= 0 || result == EOF;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
