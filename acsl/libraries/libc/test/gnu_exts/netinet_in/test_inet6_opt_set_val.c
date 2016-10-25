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
        if (inet6_opt_append(bp, len, anyint(), anyint(), 42, anyint(), &data) != -1)
            inet6_opt_set_val(data, 0, data, 42);
    }
}

void runFailure() {
    int len = inet6_opt_init(NULL, anyint());
    len = inet6_opt_append(NULL, len, anyint(), anyint(), anysize(), anyint(), NULL);
    char* bp = my_malloc(len);
    if (inet6_opt_init(bp, len) != -1) {
        char* data;
        if (inet6_opt_append(bp, len, anyint(), anyint(), 42, anyint(), &data) != -1)
            inet6_opt_set_val(NULL, 0, data, 42);
    }
}

void runFailure1() {
    int len = inet6_opt_init(NULL, anyint());
    len = inet6_opt_append(NULL, len, anyint(), anyint(), anysize(), anyint(), NULL);
    char* bp = my_malloc(len);
    if (inet6_opt_init(bp, len) != -1) {
        char* data;
        if (inet6_opt_append(bp, len, anyint(), anyint(), 42, anyint(), &data) != -1)
            inet6_opt_set_val(data, 100, data, 42);
    }
}

void runFailure2() {
    int len = inet6_opt_init(NULL, anyint());
    len = inet6_opt_append(NULL, len, anyint(), anyint(), anysize(), anyint(), NULL);
    char* bp = my_malloc(len);
    if (inet6_opt_init(bp, len) != -1) {
        char* data;
        if (inet6_opt_append(bp, len, anyint(), anyint(), 42, anyint(), &data) != -1)
            inet6_opt_set_val(data, 0, data, 100);
    }
}

void runFailure3() {
    int len = inet6_opt_init(NULL, anyint());
    len = inet6_opt_append(NULL, len, anyint(), anyint(), anysize(), anyint(), NULL);
    char* bp = my_malloc(len);
    if (inet6_opt_init(bp, len) != -1) {
        char* data;
        if (inet6_opt_append(bp, len, anyint(), anyint(), 42, anyint(), &data) != -1)
            inet6_opt_set_val(data, 0, NULL, 42);
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
        if (inet6_opt_append(bp, len, anyint(), anyint(), 42, anyint(), &data) != -1) {
            int result = inet6_opt_set_val(data, 0, data, 42);
            //@ assert result == 42 + 0;
        }
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
