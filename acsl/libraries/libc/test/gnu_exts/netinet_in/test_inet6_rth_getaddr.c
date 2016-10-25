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
        if (inet6_rth_init(bp, len, t, s)) {
            inet6_rth_getaddr(bp, anyint());
        }
    }
}

void runFailure() {
    int t = anyint();
    int s = anyint();
    int len = inet6_rth_space(t, s);
    if (len) {
        char* bp = my_malloc(len);
        if (inet6_rth_init(bp, len, t, s)) {
            inet6_rth_getaddr(NULL, anyint());
        }
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
        if (inet6_rth_init(bp, len, t, s)) {
            struct in6_addr * result = inet6_rth_getaddr(bp, anyint());
            //@ assert result == \null || \valid(result);
        }
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
