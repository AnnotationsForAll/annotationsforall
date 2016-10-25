#include "../../../test_common.h"
#include <libgen.h>

void runSuccess() {
    char buf[] = "path";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    dirname(buf);
}

void runSuccess1() {
    dirname(NULL);
}

void runFailure() {
    
}

void testValues() {
    char* result;
    
    result = dirname(NULL);
    //@ assert \valid(result);

    //@ assert vacuous: \false;
}

//FIXME: the below tests are almost certainly too strong to be proven

/*void testValues() {
    char* result;

    result = dirname(NULL);
    //@ assert result[0] == '.';
    //@ assert result[1] == '\0';
    
    //@ assert vacuous: \false;
}

void testValues1() {
    char* result;
    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = dirname(NULL);
    //@ assert result[0] == '.';
    //@ assert result[1] == '\0';
    
    //@ assert vacuous: \false;
}

void testValues2() {
    char* result;
    char buf[] = "a";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = dirname(NULL);
    //@ assert result[0] == '.';
    //@ assert result[1] == '\0';
    
    //@ assert vacuous: \false;
}

void testValues3() {
    char* result;
    char buf[] = "a/b";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = dirname(NULL);
    //@ assert result[0] == 'a';
    //@ assert result[1] == '\0';
    
    //@ assert vacuous: \false;
}*/
