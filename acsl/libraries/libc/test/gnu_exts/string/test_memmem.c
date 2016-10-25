//OPTIONS: -wp-model Typed+cast

#include "../../../test_common.h"
#include <string.h>

void runSuccess() {
    char buf[] = "Hello";
    char s1[] = "e";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';

    memmem(buf, 5, s1, 1);
}

void runSuccess1() {
    char buf[] = "Hello";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    memmem(buf, 5, buf, 5);
}

void runFailure() {
    char s1[] = "e";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    memmem(NULL, anysize(), s1, 1);
}

void runFailure1() {
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    memmem(buf, 5, NULL, anysize());
}

void testValues() {
    char* result;

    char buf[] = "Hello";
    char s1[] = "e";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';

    result = memmem(buf, 5, s1, 1);
    //@ assert result != \null ==> (\base_addr(result) == \base_addr(buf));
    
    if (result==NULL) {return;}
    int cmp = memcmp(result, s1, 1);
    //@ assert cmp == 0;

    //@ assert vacuous: \false;
}

void testValues1() {
    char* result;

    char buf[] = "Hello";
    char s1[] = "ll";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';

    result = memmem(buf, 5, s1, 2);
    //@ assert result != \null ==> (\base_addr(result) == \base_addr(buf));

    if (result==NULL) {return;}
    int cmp = memcmp(result, s1, 2);
    //@ assert cmp == 0;

    //@ assert vacuous: \false;
}
