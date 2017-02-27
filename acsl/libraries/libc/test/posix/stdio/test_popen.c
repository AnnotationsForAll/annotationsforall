#include "../../../unistd_common.h"

void runSuccess() {
    char s1[] = "file";
    char s2[] = "r";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    popen(s1, s2);
}

void runSuccess1() {
    char s1[] = "file";
    char s2[] = "w";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    popen(s1, s2);
}

/*void runFailure() {
    char s1[] = "file";
    char s2[] = "$";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    popen(s1, s2);
}*/

void runFailure1() {
    char s2[] = "r";
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    popen(NULL, s2);
}

void runFailure2() {
    char s1[] = "file";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    popen(s1, NULL);
}

void runFailure3() {
    popen(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    FILE* result;
    char s1[] = "file";
    char s2[] = "r";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    result = popen(s1, s2);
    //@ assert result == \null || \valid(result);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}