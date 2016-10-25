#include "../../../test_common.h"
#include <arpa/nameser.h>

void runSuccess() {
    u_char msg[10]; ns_msg handle;
    int bad = ns_initparse(msg, 10, &handle);
    if (!bad) {
        ns_msg_size(handle);
    }
}

void runFailure() {
    ns_msg handle;
    ns_msg_size(handle);
}

int f;
void testValues() {
    f = 2;
    
    u_char msg[10]; ns_msg handle;
    int bad = ns_initparse(msg, 10, &handle);
    if (!bad) {
        u_char* a = ns_msg_base(handle);
        u_char* b = ns_msg_end(handle);
        size_t s = ns_msg_size(handle);
        //@ assert a + s == b;
        //@ assert b - s == a;
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
