#include "../../../test_common.h"
#include <netinet/in.h>

/*@
assigns \result;
ensures \valid(\result+(0..size-1));
*/
char* my_malloc(int size);

void runSuccess() {
    int len = inet6_opt_init(NULL, anyint());
    char* bp = my_malloc(len);
    uint8_t type;
    socklen_t size;
    char* data;
    if (inet6_opt_init(bp, len) != -1) {
        inet6_opt_find(bp, len, anyint(), type, &size, &data);
    }
}

void runFailure() {
    int len = inet6_opt_init(NULL, anyint());
    char* bp = my_malloc(len);
    uint8_t type;
    socklen_t size;
    char* data;
    if (inet6_opt_init(bp, len) != -1) {
        inet6_opt_find(NULL, len, anyint(), type, &size, &data);
    }
}

void runFailure1() {
    int len = inet6_opt_init(NULL, anyint());
    char* bp = my_malloc(len);
    uint8_t type;
    socklen_t size;
    char* data;
    if (inet6_opt_init(bp, len) != -1) {
        inet6_opt_find(bp, len+1, anyint(), type, &size, &data);
    }
}

void runFailure2() {
    int len = inet6_opt_init(NULL, anyint());
    char* bp = my_malloc(len);
    uint8_t type;
    socklen_t size;
    char* data;
    if (inet6_opt_init(bp, len) != -1) {
        inet6_opt_find(bp, len, anyint(), type, NULL, &data);
    }
}

void runFailure3() {
    int len = inet6_opt_init(NULL, anyint());
    char* bp = my_malloc(len);
    uint8_t type;
    socklen_t size;
    char* data;
    if (inet6_opt_init(bp, len) != -1) {
        inet6_opt_find(bp, len, anyint(), type, &size, NULL);
    }
}

int f;
void testValues() {
    f = 2;
    
    int len = inet6_opt_init(NULL, anyint());
    char* bp = my_malloc(len);
    uint8_t type;
    socklen_t size;
    char* data;
    if (inet6_opt_init(bp, len) != -1) {
        int result = inet6_opt_find(bp, len, anyint(), type, &size, &data);
        //@ assert result != -1 ==> \valid(data+(0..size-1));
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
