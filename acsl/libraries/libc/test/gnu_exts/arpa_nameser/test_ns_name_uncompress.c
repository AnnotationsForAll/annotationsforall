#include "../../../test_common.h"
#include <arpa/nameser.h>

void runSuccess() {
    u_char msg[10];
    char buf[42];
    ns_name_uncompress(msg, msg+10, msg+5, buf, 42);
}

void runSuccess1() {
    u_char msg[10];
    char buf[42];
    ns_name_uncompress(msg+2, msg+7, msg+5, buf, 22);
}

void runFailure() {
    u_char msg[10];
    char buf[42];
    ns_name_uncompress(NULL, msg+10, msg+5, buf, 42);
}

void runFailure1() {
    u_char msg[10];
    char buf[42];
    ns_name_uncompress(msg+5, msg, msg+10, buf, 42);
}

void runFailure2() {
    u_char msg[10];
    char buf[42];
    ns_name_uncompress(msg, msg+10, NULL, buf, 42);
}

void runFailure3() {
    u_char msg[10];
    char buf[42];
    ns_name_uncompress(msg, msg+10, msg+5, NULL, anysize());
}

void runFailure4() {
    u_char msg[10];
    char buf[42];
    ns_name_uncompress(msg, msg+10, buf+5, buf, 42);
}

void runFailure5() {
    u_char msg[10];
    char buf[42];
    ns_name_uncompress(msg, msg+10, msg+5, buf, 1000);
}

int f;
void testValues() {
    f = 2;
    
    u_char msg[10];
    char buf[42];
    ns_name_uncompress(msg, msg+10, msg+5, buf, 42);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
