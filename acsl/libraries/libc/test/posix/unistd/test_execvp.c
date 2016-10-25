#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    char* argv[1];
    char *a = "abc";
    //@ assert valid_string(a); // Does not prove because char* instead of char[]. Accept anyways
    argv[0] = a;
    
    char cmd[] = "cmd";
    //@ assert \valid(cmd+(0..\block_length(cmd)-1));
    //@ assert \exists integer x; cmd[x] == '\0';
    
    execvp(cmd, argv);
}

void runFailure() {
    execvp(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    char* argv[1];
    char *a = "abc";
    argv[0] = a;
    
    char cmd[] = "cmd";
    //@ assert \valid(cmd+(0..\block_length(cmd)-1));
    //@ assert \exists integer x; cmd[x] == '\0';
    
    execvp(cmd, argv);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
