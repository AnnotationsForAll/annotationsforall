#include "../../../test_common.h"
#include <arpa/nameser.h>

void runSuccess() {
    u_char msg[10]; ns_msg handle;
    int bad = ns_initparse(msg, 10, &handle);
    if (!bad) {
        ns_msg_getflag(handle, ns_f_qr);
    }
}

void runFailure() {
    u_char msg[10]; ns_msg handle;
    int bad = ns_initparse(msg, 10, &handle);
    if (!bad) {
        ns_msg_getflag(handle, -1);
    }
}

void runFailure1() {
    ns_msg handle;
    ns_msg_getflag(handle, ns_f_qr);
}

void runFailure2() {
    u_char msg[10]; ns_msg handle;
    int bad = ns_initparse(msg, 10, &handle);
    if (!bad) {
        ns_msg_getflag(handle, ns_f_max);
    }
}

int f;
void testValues() {
    f = 2;
    
    u_char msg[10]; ns_msg handle;
    int bad = ns_initparse(msg, 10, &handle);
    if (!bad) {
        ns_msg_getflag(handle, ns_f_qr);
        ns_msg_getflag(handle, ns_f_cd);
        ns_msg_getflag(handle, ns_f_opcode);
        ns_msg_getflag(handle, ns_f_rcode);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
