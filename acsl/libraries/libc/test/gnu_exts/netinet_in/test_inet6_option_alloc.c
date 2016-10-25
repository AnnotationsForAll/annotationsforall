#include "../../../test_common.h"
#include <netinet/in.h>

/*@
assigns \result;
ensures \valid(\result+(0..size-1));
ensures \block_length(\result) == size;
*/
char* my_malloc(int size);

void runSuccess() {
    int len = 2;
    int room = inet6_option_space(len);
    char* bp = my_malloc(room);
    struct cmsghdr * cmsg;
    if (!inet6_option_init(bp, &cmsg, anyint())) {
        inet6_option_alloc(cmsg, len, anyint(), anyint());
    }
}

void runFailure() {
    int len = 2;
    int room = inet6_option_space(len);
    char* bp = my_malloc(room);
    struct cmsghdr * cmsg;
    if (!inet6_option_init(bp, &cmsg, anyint())) {
        inet6_option_alloc(NULL, len, anyint(), anyint());
    }
}

void runFailure1() {
    int len = 2;
    int room = inet6_option_space(len);
    char* bp = my_malloc(room);
    struct cmsghdr * cmsg;
    if (!inet6_option_init(bp, &cmsg, anyint())) {
        inet6_option_alloc(cmsg, len+1, anyint(), anyint());
    }
}

int f;
void testValues() {
    f = 2;
    
    int len = 2;
    int room = inet6_option_space(len);
    char* bp = my_malloc(room);
    struct cmsghdr * cmsg;
    if (!inet6_option_init(bp, &cmsg, anyint())) {
        inet6_option_alloc(cmsg, len, anyint(), anyint());
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
