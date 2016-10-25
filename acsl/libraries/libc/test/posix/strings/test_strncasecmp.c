#include "../../../test_common.h"
#include <strings.h>

void runSuccess() {
    char s1[] = "s1";
    char s2[] = "s2";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    strncasecmp(s1, s2, 5);
}

void runSuccess1() {
    char buf[] = "A";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    strncasecmp(buf, buf, 30);
}

void runFailure() {
    char s2[] = "s2";
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    strncasecmp(NULL, s2, 5);
}

void runFailure1() {
    char s1[] = "s1";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    strncasecmp(s1, NULL, 5);
}

int f;
void testValues() {
    f = 2;
    int result;
    char s1[] = "s1";
    char s2[] = "s2";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    strncasecmp(s1, s2, 5);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
