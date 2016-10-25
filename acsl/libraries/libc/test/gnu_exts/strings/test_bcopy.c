#include "../../../test_common.h"
#include <strings.h>

void runSuccess() {
    char buf[] = "BB";
    char s1[] = "AA";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    
    bcopy(s1, buf, 2);
}

void runSuccess1() {
    char buf[] = "BB";
    char s1[] = "AA";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \valid(s1+(0..\block_length(s1)-1));

    bcopy(s1, buf, 1);
}

void runSuccess2() {
    char buf[] = "BB";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    bcopy(buf, buf, 2);
}

void runFailure() {
    char buf[] = "AA";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    bcopy(NULL, buf, anysize());
}

void runFailure1() {
    char s1[] = "BB";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    
    bcopy(NULL, s1, anysize());
}

void runFailure2() {
    char buf[] = "BB";
    char s1[] = "AA";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    
    bcopy(s1, buf, 20);
}

void testValues() {
    char* result;
    char buf[] = "BB";
    char s1[] = "A";
    
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    
    bcopy(s1, buf, 1);

    int cmp = bcmp(buf, s1, 1);
    //@ assert cmp == 0;

    //@ assert vacuous: \false;
}

void testValues1() {
    char* result;
    char buf[] = "BB";
    char s1[] = "A";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \valid(s1+(0..\block_length(s1)-1));

    bcopy(s1, buf, 0);

    int cmp = bcmp(buf, s1, 0);
    //@ assert cmp == 0;

    //@ assert vacuous: \false;
}

void testValues2() {
    char* result;
    char buf[] = "BBB";
    char s1[] = "A";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \valid(s1+(0..\block_length(s1)-1));

    bcopy(s1, buf, 2);

    int cmp = bcmp(buf, s1, 2);
    //@ assert cmp == 0;

    //@ assert vacuous: \false;
}

void testValues3() {
    char* result;
    char buf[] = "BBB";
    //@ assert \valid(buf+(0..\block_length(buf)-1));

    bcopy(buf, buf, 2);
    
    int cmp = bcmp(buf, buf, 2);
    //@ assert cmp == 0;

    //@ assert vacuous: \false;
}
