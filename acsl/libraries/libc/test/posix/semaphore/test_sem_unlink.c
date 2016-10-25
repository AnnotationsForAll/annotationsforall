#include "../../../test_common.h"
#include <semaphore.h>
#include <fcntl.h>

void runSuccess() {
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    sem_unlink(buf);
}

void runFailure() {
    sem_unlink(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = sem_unlink(buf);
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
