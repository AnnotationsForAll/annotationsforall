#include "../../../test_common.h"
#include <semaphore.h>
#include <fcntl.h>

void runSuccess() {
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    sem_open(buf, O_CREAT);
}

void runSuccess1() {
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    sem_open(buf, O_EXCL);
}

void runSuccess2() {
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    sem_open(buf, O_EXCL | O_CREAT);
}

void runFailure() {
    sem_open(NULL, O_EXCL | O_CREAT);
}

int f;
void testValues() {
    f = 2;
    sem_t* result;
    
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = sem_open(buf, O_EXCL | O_CREAT);
    //@ assert result == SEM_FAILED || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
