#include "../../../test_common.h"
#include <arpa/nameser.h>

void runSuccess() {
    u_char msg[10]; ns_msg handle;
    int bad = ns_initparse(msg, 10, &handle);
    if (!bad) {
        int sects = ns_msg_count(handle, ns_s_an);
        if (sects > 0) {
            ns_rr rr;
            ns_parserr(&handle, ns_s_an, 0, &rr);
        }
    }
}

void runFailure() {
    ns_msg handle;
    int sects = ns_msg_count(handle, ns_s_pr);
    if (sects > 0) {
        ns_rr rr;
        ns_parserr(&handle, ns_s_pr, 0, &rr);
    }
}

void runFailure1() {
    u_char msg[10]; ns_msg handle;
    int bad = ns_initparse(msg, 10, &handle);
    if (!bad) {
        ns_rr rr;
        ns_parserr(&handle, ns_s_an, -1, &rr);
    }
}

void runFailure2() {
    u_char msg[10]; ns_msg handle;
    int bad = ns_initparse(msg, 10, &handle);
    if (!bad) {
        int sects = ns_msg_count(handle, ns_s_max);
        if (sects > 0) {
            ns_rr rr;
            ns_parserr(&handle, ns_s_max, 0, &rr);
        }
    }
}

int f;
void testValues() {
    f = 2;
    
    u_char msg[10]; ns_msg handle;
    int bad = ns_initparse(msg, 10, &handle);
    if (!bad) {
        int sects = ns_msg_count(handle, ns_s_ns);
        if (sects > 0) {
            ns_rr rr;
            int result = ns_parserr(&handle, ns_s_ns, 0, &rr);
            //@ assert result == 0 ==> valid_string((char*)(rr.name));
        }
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
