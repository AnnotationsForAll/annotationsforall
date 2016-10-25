//OPTIONS: -wp-model Typed+cast

#include "../../../unistd_common.h"
#include <fcntl.h>

void runSuccess() {
    struct file_handle handle; handle.handle_bytes = 0;
    int m;
    open_by_handle_at(m, &handle, anyint());
}

void runFailure() {
    struct file_handle handle; handle.handle_bytes = 0;
    int m;
    open_by_handle_at(m, NULL, anyint());
}

void runFailure1() {
    struct file_handle handle; handle.handle_bytes = 30;
    int m;
    open_by_handle_at(m, &handle, anyint());
}

int f;
void testValues() {
    f = 2;
    
    struct file_handle handle; handle.handle_bytes = 0;
    int m;
    open_by_handle_at(m, &handle, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
