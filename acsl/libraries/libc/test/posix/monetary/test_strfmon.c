#include "../../../test_common.h"
#include <monetary.h>
#include <errno.h>

void runSuccess() {
    char s[10];
    char buf[] = "%i";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    strfmon(s, 10, buf, anydouble());
}

void runFailure() {
    char buf[] = "%i";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    strfmon(NULL, 10, buf, anydouble());
}

void runFailure1() {
    char s[10];
    char buf[] = "%i";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    strfmon(s, 20, buf, anydouble());
}

void runFailure2() {
    char s[10];
    
    strfmon(s, 20, NULL, anydouble());
}

int f;
void testValues() {
    f = 2;
    ssize_t result;
    
    char s[10];
    char buf[] = "%i";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    errno = 0;
    result = strfmon(s, 10, buf, anydouble());
    //@ assert result == (ssize_t)-1 ==> errno != 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
