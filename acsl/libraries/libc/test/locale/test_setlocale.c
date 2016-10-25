#include "../../test_common.h"
#include <locale.h>
#include <stddef.h>

void runSuccess() {
    char buf[] = "C";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    setlocale(LC_ALL, buf);
}

void runSuccess1() {
    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    setlocale(LC_ALL, buf);
}

void runSuccess2() {
    setlocale(LC_ALL, NULL);
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    char* result;
    char buf[] = "C";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = setlocale(LC_ALL, buf);
    //@ assert result!=\null ==> \valid(result);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}

void testValues1() {
    f = 2;
    char* result;
    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    result = setlocale(LC_ALL, buf);
    //@ assert result!=\null ==> \valid(result);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}

void testValues2() {
    f = 2;
    char* result;

    result = setlocale(LC_ALL, NULL);
    //@ assert result != \null ==> \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
