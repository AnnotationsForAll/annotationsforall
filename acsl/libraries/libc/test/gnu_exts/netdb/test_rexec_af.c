#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    char host[] = "host";
    char* hostp = host;
    int fd;
    rexec_af(&hostp, anyint(), anystring(), anystring(), anystring(), &fd, anyint());
}

void runSuccess1() {
    char host[] = "host";
    char* hostp = host;
    int fd;
    rexec_af(&hostp, anyint(), anystring(), anystring(), anystring(), NULL, anyint());
}

void runFailure() {
    char host[] = "host";
    char* hostp = host;
    int fd;
    rexec_af(NULL, anyint(), anystring(), anystring(), anystring(), NULL, anyint());
}

void runFailure1() {
    char host[] = "host";
    char* hostp = NULL;
    int fd;
    rexec_af(&hostp, anyint(), anystring(), anystring(), anystring(), &fd, anyint());
}

int f;
void testValues() {
    f = 2;
    
    char host[] = "host";
    char* hostp = host;
    int fd;
    rexec_af(&hostp, anyint(), anystring(), anystring(), anystring(), &fd, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
