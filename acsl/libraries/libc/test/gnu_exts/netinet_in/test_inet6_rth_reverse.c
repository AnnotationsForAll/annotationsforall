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
    char* bp = my_malloc(len);
    int t2 = anyint();
    int s2 = anyint();
    int len2 = inet6_rth_space(t2, s2);
    char* bp2 = my_malloc(len2);
    if (len) {
        if (inet6_rth_init(bp, len, t, s)) {
            if (len2) {
                if (inet6_rth_init(bp2, len2, t2, s2)) {
                    inet6_rth_reverse(bp, bp2);
                }
            }
        }
    }
}

void runFailure() {
    int t = anyint();
    int s = anyint();
    int len = inet6_rth_space(t, s);
    char* bp = my_malloc(len);
    int t2 = anyint();
    int s2 = anyint();
    int len2 = inet6_rth_space(t2, s2);
    char* bp2 = my_malloc(len2);
    if (len) {
        if (inet6_rth_init(bp, len, t, s)) {
            if (len2) {
                if (inet6_rth_init(bp2, len2, t2, s2)) {
                    inet6_rth_reverse(NULL, bp2);
                }
            }
        }
    }
}

void runFailure1() {
    int t = anyint();
    int s = anyint();
    int len = inet6_rth_space(t, s);
    char* bp = my_malloc(len);
    int t2 = anyint();
    int s2 = anyint();
    int len2 = inet6_rth_space(t2, s2);
    char* bp2 = my_malloc(len2);
    if (len) {
        if (inet6_rth_init(bp, len, t, s)) {
            if (len2) {
                if (inet6_rth_init(bp2, len2, t2, s2)) {
                    inet6_rth_reverse(bp, NULL);
                }
            }
        }
    }
}

int f;
void testValues() {
    f = 2;
    
    int t = anyint();
    int s = anyint();
    int len = inet6_rth_space(t, s);
    char* bp = my_malloc(len);
    int t2 = anyint();
    int s2 = anyint();
    int len2 = inet6_rth_space(t2, s2);
    char* bp2 = my_malloc(len2);
    if (len) {
        if (inet6_rth_init(bp, len, t, s)) {
            if (len2) {
                if (inet6_rth_init(bp2, len2, t2, s2)) {
                    inet6_rth_reverse(bp, bp2);
                }
            }
        }
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
