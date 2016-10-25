#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    char host[] = "host";
    char* hostp = host;
    int fd;
    rcmd(&hostp, anyint(), anystring(), anystring(), anystring(), &fd);
}

void runSuccess1() {
    char host[] = "host";
    char* hostp = host;
    int fd;
    rcmd(&hostp, anyint(), anystring(), anystring(), anystring(), NULL);
}

void runFailure() {
    char host[] = "host";
    char* hostp = host;
    int fd;
    rcmd(NULL, anyint(), anystring(), anystring(), anystring(), NULL);
}

void runFailure1() {
    char host[] = "host";
    char* hostp = NULL;
    int fd;
    rcmd(&hostp, anyint(), anystring(), anystring(), anystring(), &fd);
}

int f;
void testValues() {
    f = 2;
    
    char host[] = "host";
    char* hostp = host;
    int fd;
    rcmd(&hostp, anyint(), anystring(), anystring(), anystring(), &fd);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
