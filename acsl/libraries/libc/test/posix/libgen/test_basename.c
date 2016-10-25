#include "../../../test_common.h"
#include <libgen.h>

void runSuccess() {
    char buf[] = "path";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    basename(buf);
}

void runSuccess1() {
    basename(NULL);
}

void runFailure() {
    
}

void testValues() {
    char* result;
    
    result = basename(NULL);
    //@ assert \valid(result);

    //@ assert vacuous: \false;
}

//FIXME: the below tests are almost certainly too strong to be proven

/*void testValues() {
    char* result;

    result = basename(NULL);
    //@ assert result[0] == '.';
    //@ assert result[1] == '\0';
    
    //@ assert vacuous: \false;
}

void testValues1() {
    char* result;
    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = basename(NULL);
    //@ assert result[0] == '.';
    //@ assert result[1] == '\0';
    
    //@ assert vacuous: \false;
}

void testValues2() {
    char* result;
    char buf[] = "a";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = basename(NULL);
    //@ assert result[0] == 'a';
    //@ assert result[1] == '\0';
    
    //@ assert vacuous: \false;
}

void testValues3() {
    char* result;
    char buf[] = "a/b";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = basename(NULL);
    //@ assert result[0] == 'b';
    //@ assert result[1] == '\0';
    
    //@ assert vacuous: \false;
}

void testValues4() {
    char* result;
    char buf[] = "/";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = basename(NULL);
    //@ assert result[0] == '/';
    //@ assert result[1] == '\0';
    
    //@ assert vacuous: \false;
}

void testValues5() {
    char* result;
    char buf[] = "//";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = basename(NULL);
    //@ assert result[0] == '/';
    //@ assert result[1] == '\0' || (result[1] == '/' && result[2] == '\0');
    
    //@ assert vacuous: \false;
}*/
