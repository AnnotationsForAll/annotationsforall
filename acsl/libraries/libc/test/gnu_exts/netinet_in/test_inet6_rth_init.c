#include "../../../test_common.h"
#include <netinet/in.h>

/*@
assigns \result;
ensures \valid(\result+(0..size-1));
*/
char* my_malloc(int size);

void runSuccess() {
    int t = anyint();
    int s = anyint();
    int len = inet6_rth_space(t, s);
    if (len) {
        char* bp = my_malloc(len);
        inet6_rth_init(bp, len, t, s);
    }
}

void runFailure() {
    int t = anyint();
    int s = anyint();
    int len = inet6_rth_space(t, s);
    if (len) {
        char* bp = my_malloc(len);
        inet6_rth_init(NULL, len, t, s);
    }
}

void runFailure1() {
    int t = anyint();
    int s = anyint();
    int len = inet6_rth_space(t, s);
    if (len) {
        char* bp = my_malloc(len);
        inet6_rth_init(bp, len+1, t, s);
    }
}

void runFailure2() {
    int t = anyint();
    int s = anyint();
    int len = inet6_rth_space(t, s);
    if (len) {
        char* bp = my_malloc(len);
        inet6_rth_init(bp, 0, t, s);
    }
}

int f;
void testValues() {
    f = 2;
    
    int t = anyint();
    int s = anyint();
    int len = inet6_rth_space(t, s);
    if (len) {
        char* bp = my_malloc(len);
        char* result = inet6_rth_init(bp, len, t, s);
        //@ assert result == \null || result == bp;
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
