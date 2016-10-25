//OPTIONS: -wp-model Typed+cast

#include "../../../unistd_common.h"
#include <fcntl.h>

void runSuccess() {
    struct file_handle handle; handle.handle_bytes = 0;
    int m;
    name_to_handle_at(anyint(), anystring(), &handle, &m, anyint());
}

void runFailure() {
    struct file_handle handle; handle.handle_bytes = 0;
    int m;
    name_to_handle_at(anyint(), NULL, &handle, &m, anyint());
}

void runFailure1() {
    struct file_handle handle; handle.handle_bytes = 0;
    int m;
    name_to_handle_at(anyint(), anystring(), NULL, &m, anyint());
}

void runFailure2() {
    struct file_handle handle; handle.handle_bytes = 0;
    int m;
    name_to_handle_at(anyint(), anystring(), &handle, NULL, anyint());
}

void runFailure3() {
    struct file_handle handle; handle.handle_bytes = 30;
    int m;
    name_to_handle_at(anyint(), anystring(), &handle, &m, anyint());
}

int f;
void testValues() {
    f = 2;
    
    struct file_handle handle; handle.handle_bytes = 0;
    int m;
    name_to_handle_at(anyint(), anystring(), &handle, &m, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
