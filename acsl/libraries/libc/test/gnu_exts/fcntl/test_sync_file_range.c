#include "../../../unistd_common.h"
#include <fcntl.h>

void runSuccess() {
    int fd = VALID_FD;
    if (fd >= 0) {
        sync_file_range(fd, anyint(), anyint(), anyint());
    }
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    int fd = VALID_FD;
    if (fd >= 0) {
        sync_file_range(fd, anyint(), anyint(), anyint());
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
