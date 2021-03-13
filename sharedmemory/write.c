/*
 * This code write in a shared memory object.
 * You need to compile using "gcc -o write write.c -lrt".
 */
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SMOBJ_NAME "/myMemoryObj"

int main(void){

    int fd = 0;
    char buf[] = "Hello this is writting process\n";
    char *ptr = NULL;

    if((fd = shm_open(SMOBJ_NAME, O_RDWR, 0)) == -1){
        printf("error, shared memory could not be created\n");
        exit(1);
    }

    if((ptr = mmap(0, sizeof(buf), PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED){
        printf("error in memory mapping\n");
        exit(1);
    }

    memcpy(ptr, buf, sizeof(buf));
    close(fd);

    return 0;
}
