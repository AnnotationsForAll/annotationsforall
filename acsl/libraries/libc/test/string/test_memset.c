#include "../../test_common.h"
#include <string.h>

void runSuccess() {
    char buf[] = "AAA";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    
    memset(buf, 'a', 1);
    memset(buf, '?', 2);
    memset(buf, '\0', 3);
}

void runFailure() {
    memset(NULL, 'x', 4);
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    char buf[] = "AAA";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    
    result = memset(buf, '!', 2);
    //@ assert result == buf;
    //@ assert result[0] == '!';
    //@ assert result[1] == '!';
    //@ assert result[2] == 'A';
    //@ assert result[3] == '\0';
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}

int f;
void testValues1() {
    f = 2;
    char* result;
    
    char buf[] = "AAA";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    
    result = memset(buf, '!', 0);
    //@ assert result == buf;
    //@ assert result[0] == 'A';
    //@ assert result[1] == 'A';
    //@ assert result[2] == 'A';
    //@ assert result[3] == '\0';
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}

int f;
void testValues2() {
    f = 2;
    char* result;
    
    char buf[] = "AAA";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    
    result = memset(buf, '!', 4);
    //@ assert result == buf;
    //@ assert result[0] == '!';
    //@ assert result[1] == '!';
    //@ assert result[2] == '!';
    //@ assert result[3] == '!';
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
