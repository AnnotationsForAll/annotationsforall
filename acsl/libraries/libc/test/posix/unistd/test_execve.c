#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    char* argv[1];
    char *a = "abc";
    //@ assert valid_string(a); // Does not prove because char* instead of char[]. Accept anyways
    argv[0] = a;
    
    char* arge[1];
    char *b = "abc";
    //@ assert valid_string(b); // Does not prove because char* instead of char[]. Accept anyways
    arge[0] = b;
    
    char cmd[] = "cmd";
    //@ assert \valid(cmd+(0..\block_length(cmd)-1));
    //@ assert \exists integer x; cmd[x] == '\0';
    
    execve(cmd, argv, arge);
}

void runFailure() {
    execve(NULL, NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    char* argv[1];
    char *a = "abc";
    argv[0] = a;
    
    char* arge[1];
    char *b = "abc";
    arge[0] = b;
    
    char cmd[] = "cmd";
    //@ assert \valid(cmd+(0..\block_length(cmd)-1));
    //@ assert \exists integer x; cmd[x] == '\0';
    
    execve(cmd, argv, arge);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
