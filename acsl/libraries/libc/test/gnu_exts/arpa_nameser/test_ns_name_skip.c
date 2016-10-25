#include "../../../test_common.h"
#include <arpa/nameser.h>

void runSuccess() {
    u_char msg[10];
    u_char* p = msg;
    ns_name_skip(&p, msg+10);
}

void runFailure() {
    u_char msg[10];
    u_char* p = msg;
    ns_name_skip(NULL, msg+10);
}

void runFailure1() {
    u_char msg[10];
    u_char* p = msg;
    ns_name_skip(&p, NULL);
}

void runFailure2() {
    u_char msg[10];
    u_char* p = msg+5;
    ns_name_skip(&p, msg);
}

void runFailure3() {
    u_char msg[10];
    u_char* p = msg;
    ns_name_skip(&p, msg+20);
}

int f;
void testValues() {
    f = 2;
    
    u_char msg[10];
    u_char* p = msg;
    ns_name_skip(&p, msg+10);
    //@ assert p >= ((u_char*)msg);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
