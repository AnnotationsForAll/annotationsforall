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
            inet6_rth_segments(bp);
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
            inet6_rth_segments(NULL);
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
            int result = inet6_rth_segments(bp);
            //@ assert result == s;
        }
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
