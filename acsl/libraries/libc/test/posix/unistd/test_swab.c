#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    char s1[] = "s1";
    char s2[] = "!!";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    
    swab(s1, s2, 2);
}

void runFailure() {
    swab(NULL, NULL, 5);
}

void runFailure1() {
    char s1[] = "s1";
    char s2[] = "!!";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    
    swab(s1, s2, 10);
}

int f;
void testValues() {
    f = 2;
    char* result;
    char s1[] = "s1";
    char s2[] = "!!";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    
    swab(s1, s2, 2);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}

//FIXME: the below tests are almost certainly too strong to be proven

/*
void testValues() {
    f = 2;
    char* result;
    char s1[] = "s1";
    char s2[] = "!!";

    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    
    swab(s1, s2, 2);
    //@ assert s1[0] == 's';
    //@ assert s1[1] == '1';
    //@ assert s1[2] == '\0';
    //@ assert s2[0] == '1';
    //@ assert s2[1] == 's';
    //@ assert s2[2] == '\0';
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}*/
