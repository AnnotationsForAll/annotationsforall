#include "../../../test_common.h"
#include <semaphore.h>
#include <fcntl.h>

void runSuccess() {
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    sem_t* sem = sem_open(buf, O_CREAT);
    if (sem == SEM_FAILED) {return;}

    sem_close(sem);
}

void runFailure() {
    sem_close(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    sem_t* sem = sem_open(buf, O_CREAT);
    if (sem == SEM_FAILED) {return;}
    
    result = sem_close(sem);
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
