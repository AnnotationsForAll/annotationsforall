#include "../../../test_common.h"
#include <netinet/in.h>

/*@
assigns \result;
ensures \valid(\result+(0..size-1));
*/
char* my_malloc(int size);

void runSuccess() {
    int len = inet6_opt_init(NULL, anyint());
    len = inet6_opt_finish(NULL, len, anyint());
    char* bp = my_malloc(len);
    if (inet6_opt_init(bp, len) != -1) {
        inet6_opt_finish(bp, len, anyint());
    }
}

void runFailure() {
    int len = inet6_opt_init(NULL, anyint());
    len = inet6_opt_finish(NULL, len, anyint());
    char* bp = my_malloc(len);
    if (inet6_opt_init(bp, len) != -1) {
        inet6_opt_finish(bp, len+1, anyint());
    }
}

int f;
void testValues() {
    f = 2;
    
    int len = inet6_opt_init(NULL, anyint());
    len = inet6_opt_finish(NULL, len, anyint());
    char* bp = my_malloc(len);
    if (inet6_opt_init(bp, len) != -1) {
        inet6_opt_finish(bp, len, anyint());
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
