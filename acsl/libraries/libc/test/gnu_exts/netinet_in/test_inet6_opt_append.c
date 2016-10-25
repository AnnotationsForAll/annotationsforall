#include "../../../test_common.h"
#include <netinet/in.h>

/*@
assigns \result;
ensures \valid(\result+(0..size-1));
*/
char* my_malloc(int size);

void runSuccess() {
    int len = inet6_opt_init(NULL, anyint());
    len = inet6_opt_append(NULL, len, anyint(), anyint(), anysize(), anyint(), NULL);
    char* bp = my_malloc(len);
    if (inet6_opt_init(bp, len) != -1) {
        char* data;
        inet6_opt_append(bp, len, anyint(), anyint(), anysize(), anyint(), &data);
    }
}

void runFailure() {
    int len = inet6_opt_init(NULL, anyint());
    len = inet6_opt_append(NULL, len, anyint(), anyint(), anysize(), anyint(), NULL);
    char* bp = my_malloc(len);
    if (inet6_opt_init(bp, len) != -1) {
        char* data;
        inet6_opt_append(bp, len, anyint(), anyint(), anysize(), anyint(), NULL);
    }
}

void runFailure1() {
    int len = inet6_opt_init(NULL, anyint());
    len = inet6_opt_append(NULL, len, anyint(), anyint(), anysize(), anyint(), NULL);
    char* bp = my_malloc(len);
    if (inet6_opt_init(bp, len) != -1) {
        char* data;
        inet6_opt_append(bp, len+1, anyint(), anyint(), anysize(), anyint(), &data);
    }
}

int f;
void testValues() {
    f = 2;
    
    int len = inet6_opt_init(NULL, anyint());
    len = inet6_opt_append(NULL, len, anyint(), anyint(), anysize(), anyint(), NULL);
    char* bp = my_malloc(len);
    if (inet6_opt_init(bp, len) != -1) {
        char* data;
        int result = inet6_opt_append(bp, len, anyint(), anyint(), 42, anyint(), &data);
        //@ assert result != -1 ==> \valid(data+(0..42-1));
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
