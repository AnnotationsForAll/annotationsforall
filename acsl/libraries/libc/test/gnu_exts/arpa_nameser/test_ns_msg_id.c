#include "../../../test_common.h"
#include <arpa/nameser.h>

void runSuccess() {
    u_char msg[10]; ns_msg handle;
    int bad = ns_initparse(msg, 10, &handle);
    if (!bad) {
        ns_msg_id(handle);
    }
}

void runFailure() {
    ns_msg handle;
    ns_msg_id(handle);
}

int f;
void testValues() {
    f = 2;
    
    u_char msg[10]; ns_msg handle;
    int bad = ns_initparse(msg, 10, &handle);
    if (!bad) {
        ns_msg_id(handle);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
