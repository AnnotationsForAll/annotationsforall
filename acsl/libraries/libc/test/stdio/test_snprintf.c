#include "../../stdio_common.h"

void runSuccess() {
    char buf[10];
    char s1[] = "%s";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    snprintf(buf, 10, s1, "Hello");
    snprintf(buf, 5, s1, "Hello");
}

void runFailure() {
    char s1[] = "%s";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    snprintf(NULL, anysize(), s1, "Hello");
}

void runFailure1() {
    char buf[10];
    
    snprintf(buf, 10, NULL, "Hello");
}

void runFailure2() {
    char buf[10];
    char s1[] = "%s";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    snprintf(buf, 20, s1, "Hello");
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[10];
    char s1[] = "%s";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    snprintf(buf, 10, s1, "Hello");
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
