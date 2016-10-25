#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    char buf[10];
    char s1[] = "path";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    readlink(s1, buf, 10);
}

void runFailure() {
    char buf[10];
    char s1[] = "path";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    readlink(s1, buf, 20);
}

void runFailure1() {
    char s1[] = "path";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    readlink(s1, NULL, 10);
}

int f;
void testValues() {
    f = 2;
    ssize_t result;
    char buf[10];
    char s1[] = "path";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    result = readlink(s1, buf, 10);
    //@ assert result >= -1;
    //@ assert result != -1 ==> \valid_read(buf+(0..result-1));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
