#include "../../../test_common.h"
#include <stdio.h>

void runSuccess() {
   char s[10];
   char buf[] = "r";
   //@ assert \valid(buf+(0..\block_length(buf)-1));
   //@ assert \exists integer x; buf[x] == '\0';
   
   fmemopen(s, 10, buf);
}

void runSuccess1() {
   char buf[] = "r";
   //@ assert \valid(buf+(0..\block_length(buf)-1));
   //@ assert \exists integer x; buf[x] == '\0';
   
   fmemopen(NULL, anysize(), buf);
}

void runFailure() {
    char s[10];
    
    fmemopen(s, 10, NULL);
}

void runFailure1() {
   char s[10];
   char buf[] = "r";
   //@ assert \valid(buf+(0..\block_length(buf)-1));
   //@ assert \exists integer x; buf[x] == '\0';
   
   fmemopen(s, 20, buf);
}

int f;
void testValues() {
    f = 2;
    FILE* result;
    char s[10];
    char buf[] = "r";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = fmemopen(s, 10, buf);
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
