#include "../../../unistd_common.h"
#include <fcntl.h>

void runSuccess() {
    char buf1[10];
    char buf2[5];
    struct iovec iov[] = {
            {
                    .iov_base = buf1,
                    .iov_len = 10
            },
            {
                    .iov_base = buf2,
                    .iov_len = 5
            }
    };
    vmsplice(anyint(), iov, 2, anyint());
}

void runFailure() {
    vmsplice(anyint(), NULL, anysize(), anyint());
}

void runFailure1() {
    char buf1[10];
    char buf2[5];
    struct iovec iov[] = {
            {
                    .iov_base = buf1,
                    .iov_len = 10
            },
            {
                    .iov_base = buf2,
                    .iov_len = 5
            }
    };
    vmsplice(anyint(), iov, 5, anyint());
}

void runFailure2() {
    char buf1[10];
    char buf2[5];
    struct iovec iov[] = {
            {
                    .iov_base = buf1,
                    .iov_len = 10
            },
            {
                    .iov_base = NULL,
                    .iov_len = 5
            }
    };
    vmsplice(anyint(), iov, 2, anyint());
}

void runFailure3() {
    char buf1[10];
    char buf2[5];
    struct iovec iov[] = {
            {
                    .iov_base = buf1,
                    .iov_len = 20
            },
            {
                    .iov_base = buf2,
                    .iov_len = 5
            }
    };
    vmsplice(anyint(), iov, 2, anyint());
}

int f;
void testValues() {
    f = 2;
    
    char buf1[10];
    char buf2[5];
    struct iovec iov[] = {
            {
                    .iov_base = buf1,
                    .iov_len = 10
            },
            {
                    .iov_base = buf2,
                    .iov_len = 5
            }
    };
    vmsplice(anyint(), iov, 2, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
