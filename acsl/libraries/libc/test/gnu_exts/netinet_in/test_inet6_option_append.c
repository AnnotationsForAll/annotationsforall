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
    uint8_t buf[] = {3, len, anyint(), anyint()};
    if (!inet6_option_init(bp, &cmsg, anyint())) {
        inet6_option_append(cmsg, buf, anyint(), anyint());
    }
}

void runFailure() {
    int len = 2;
    int room = inet6_option_space(len);
    char* bp = my_malloc(room);
    struct cmsghdr * cmsg;
    uint8_t buf[] = {3, 2, anyint(), anyint()};
    if (!inet6_option_init(bp, &cmsg, anyint())) {
        inet6_option_append(NULL, buf, anyint(), anyint());
    }
}

void runFailure1() {
    int len = 2;
    int room = inet6_option_space(len);
    char* bp = my_malloc(room);
    struct cmsghdr * cmsg;
    uint8_t buf[] = {3, 2, anyint(), anyint()};
    if (!inet6_option_init(bp, &cmsg, anyint())) {
        inet6_option_append(cmsg, NULL, anyint(), anyint());
    }
}

void runFailure2() {
    int len = 2;
    int room = inet6_option_space(len);
    char* bp = my_malloc(room);
    struct cmsghdr * cmsg;
    uint8_t buf[] = {3, 4, anyint(), anyint()};
    if (!inet6_option_init(bp, &cmsg, anyint())) {
        inet6_option_append(cmsg, buf, anyint(), anyint());
    }
}

int f;
void testValues() {
    f = 2;
    
    int len = 2;
    int room = inet6_option_space(len);
    char* bp = my_malloc(room);
    struct cmsghdr * cmsg;
    uint8_t buf[] = {3, 2, anyint(), anyint()};
    if (!inet6_option_init(bp, &cmsg, anyint())) {
        inet6_option_append(cmsg, buf, anyint(), anyint());
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
