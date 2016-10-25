#include "../../../test_common.h"
#include <arpa/nameser.h>

void runSuccess() {
    u_char msg[10]; ns_msg handle;
    int bad = ns_initparse(msg, 10, &handle);
    if (!bad) {
        ns_msg_count(handle, ns_s_an);
    }
}

void runFailure() {
    ns_msg handle;
    ns_msg_count(handle, ns_s_pr);
}

void runFailure1() {
    u_char msg[10]; ns_msg handle;
    int bad = ns_initparse(msg, 10, &handle);
    if (!bad) {
        ns_msg_count(handle, ns_s_max);
    }
}

int f;
void testValues() {
    f = 2;
    
    u_char msg[10]; ns_msg handle;
    int bad = ns_initparse(msg, 10, &handle);
    if (!bad) {
        ns_msg_count(handle, ns_s_ar);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
