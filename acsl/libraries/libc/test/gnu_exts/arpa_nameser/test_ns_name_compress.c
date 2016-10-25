#include "../../../test_common.h"
#include <arpa/nameser.h>

void runSuccess() {
    u_char buf[10];
    u_char s[10];
    u_char* ps[5] = {s, NULL, NULL, NULL, NULL};
    ns_name_compress(anystring(), buf, 10, ps, ps+5);
}

void runFailure() {
    u_char buf[10];
    u_char s[10];
    u_char* ps[5] = {s, NULL, NULL, NULL, NULL};
    ns_name_compress(NULL, buf, 10, ps, ps+5);
}

void runFailure1() {
    u_char buf[10];
    u_char s[10];
    u_char* ps[5] = {s, NULL, NULL, NULL, NULL};
    ns_name_compress(anystring(), NULL, anysize(), ps, ps+5);
}

void runFailure2() {
    u_char buf[10];
    u_char s[10];
    u_char* ps[5] = {s, NULL, NULL, NULL, NULL};
    ns_name_compress(anystring(), buf, 10, NULL, ps+5);
}

void runFailure3() {
    u_char buf[10];
    u_char s[10];
    u_char* ps[5] = {s, NULL, NULL, NULL, NULL};
    ns_name_compress(anystring(), buf, 10, ps, NULL);
}

void runFailure4() {
    u_char buf[10];
    u_char s[10];
    u_char* ps[5] = {s, NULL, NULL, NULL, NULL};
    ns_name_compress(anystring(), buf, 10, ps+5, ps);
}

int f;
void testValues() {
    f = 2;
    
    u_char buf[10];
    u_char s[10];
    u_char* ps[5] = {s, NULL, NULL, NULL, NULL};
    ns_name_compress(anystring(), buf, 10, ps, ps+5);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
