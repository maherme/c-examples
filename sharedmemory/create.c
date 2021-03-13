/*
 * This code create a shared memory objet, which you can find in
 * /dev/shm directory.
 * For compiling you need to use "gcc -o create create.c -lrt"
 */
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define SMOBJ_NAME "/myMemoryObj"
#define SMOBJ_SIZE 200

int main(void){

    int fd = 0;

    if((fd = shm_open(SMOBJ_NAME, O_CREAT|O_RDWR, 00600)) == -1){
        printf("error, shared memory could not be created\n");
        exit(1);
    }

    if(ftruncate(fd, SMOBJ_SIZE) == -1){
        printf("error, shared memory could not be resized\n");
        exit(1);
    }

    close(fd);

    return 0;
}
