#include "../../../test_common.h"
#include <regex.h>

void runSuccess() {
    char buf[10];
    char s[] = "pat";
    //@ assert \valid(s+(0..\block_length(s)-1));
    //@ assert \exists integer x; s[x] == '\0';
    regex_t preg;
    regcomp(&preg, s, anyint());

    regerror(anyint(), &preg, buf, 10);
}

void runSuccess1() {
    char buf[10];
    
    regerror(anyint(), NULL, buf, 10);
}

void runFailure() {
    char buf[10];
    char s[] = "pat";
    //@ assert \valid(s+(0..\block_length(s)-1));
    //@ assert \exists integer x; s[x] == '\0';
    regex_t preg;
    regcomp(&preg, s, anyint());
    
    regerror(anyint(), &preg, buf, 20);
}

void runFailure1() {
    char s[] = "pat";
    //@ assert \valid(s+(0..\block_length(s)-1));
    //@ assert \exists integer x; s[x] == '\0';
    regex_t preg;
    regcomp(&preg, s, anyint());

    regerror(anyint(), &preg, NULL, 5000);
}

int f;
void testValues() {
    f = 2;
    size_t result;
    char buf[10];
    char s[] = "pat";
    //@ assert \valid(s+(0..\block_length(s)-1));
    //@ assert \exists integer x; s[x] == '\0';
    regex_t preg;
    regcomp(&preg, s, anyint());
    
    result = regerror(anyint(), &preg, buf, 10);
    //@ assert 0 <= result <= 10;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
