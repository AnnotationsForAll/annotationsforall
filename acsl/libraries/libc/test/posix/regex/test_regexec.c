#include "../../../test_common.h"
#include <regex.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern regex_t * anyregex();

void runSuccess() {
    char buf[] = "str";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    regmatch_t matbuf[4];
    char s[] = "pat";
    //@ assert \valid(s+(0..\block_length(s)-1));
    //@ assert \exists integer x; s[x] == '\0';
    regex_t preg;
    regcomp(&preg, s, anyint());
    
    regexec(&preg, buf, 4, matbuf, anyint());
}

void runFailure() {
    char buf[] = "str";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    regmatch_t matbuf[4];
    
    regexec(NULL, buf, 4, matbuf, anyint());
}

void runFailure1() {
    regmatch_t matbuf[4];
    char s[] = "pat";
    //@ assert \valid(s+(0..\block_length(s)-1));
    //@ assert \exists integer x; s[x] == '\0';
    regex_t preg;
    regcomp(&preg, s, anyint());
    
    regexec(&preg, NULL, 4, matbuf, anyint());
}

void runFailure2() {
    char buf[] = "str";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    char s[] = "pat";
    //@ assert \valid(s+(0..\block_length(s)-1));
    //@ assert \exists integer x; s[x] == '\0';
    regex_t preg;
    regcomp(&preg, s, anyint());
    
    regexec(&preg, buf, 4, NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "str";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    regmatch_t matbuf[4];
    char s[] = "pat";
    //@ assert \valid(s+(0..\block_length(s)-1));
    //@ assert \exists integer x; s[x] == '\0';
    regex_t preg;
    regcomp(&preg, s, anyint());
    
    regexec(&preg, buf, 4, matbuf, anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
