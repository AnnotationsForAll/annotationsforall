#include "../../../stdio_common.h"
#include <stdio.h>

ssize_t my_cookie_read_function(void *cookie, char *buffer, size_t size) {
    return anylonglong();
}

ssize_t my_cookie_write_function(void *cookie, const char *buffer, size_t size) {
    return anylonglong();
}

int my_cookie_seek_function(void *cookie, off64_t *position, int whence) {
    return anyint();
}

int my_cookie_close_function(void *cookie) {
    return anyint();
}

void runSuccess() {
    cookie_io_functions_t info = {my_cookie_read_function,my_cookie_write_function,my_cookie_seek_function,my_cookie_close_function};
    char buf[] = "r";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    fopencookie(NULL, buf, info);
}

void runFailure() {
    cookie_io_functions_t info = {my_cookie_read_function,my_cookie_write_function,my_cookie_seek_function,my_cookie_close_function};
    fopencookie(NULL, NULL, info);
}

int f;
void testValues() {
    f = 2;
    
    cookie_io_functions_t info = {my_cookie_read_function,my_cookie_write_function,my_cookie_seek_function,my_cookie_close_function};
    char buf[] = "r";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    fopencookie(NULL, buf, info);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
