#include "../../../test_common.h"
#include <arpa/nameser.h>

void runSuccess() {
    u_char buf[10];
    ns_find_tsig(buf, buf+10);
}

void runFailure() {
    u_char buf[10];
    ns_find_tsig(NULL, buf+10);
}

void runFailure1() {
    u_char buf[10];
    ns_find_tsig(buf, NULL);
}

void runFailure2() {
    u_char buf[10];
    ns_find_tsig(buf, buf+20);
}

void runFailure3() {
    u_char buf[10];
    ns_find_tsig(buf+5, buf);
}

int f;
void testValues() {
    f = 2;
    
    u_char buf[10];
    u_char* result = ns_find_tsig(buf, buf+10);
    //@ assert result == \null || \valid(result);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
