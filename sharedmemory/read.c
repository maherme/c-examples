/*
 * This code read from a shared memory object.
 * For compiling this code you need to use "gcc -o read read.c -lrt"
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

#define SOBJ_NAME "/myMemoryObj"

int main(void){

    int fd = 0;
    char *ptr = NULL;
    struct stat shmobj_st;

    if((fd = shm_open(SOBJ_NAME, O_RDONLY, 00400)) == -1){
        printf("error file descriptor %s\n", strerror(errno));
        exit(1);
    }

    if(fstat(fd, &shmobj_st) == -1){
        printf("error fstat\n");
        exit(1);
    }

    if((ptr = mmap(NULL, shmobj_st.st_size, PROT_READ, MAP_SHARED, fd, 0)) == MAP_FAILED){
        printf("error, map failed in read mapping process: %s\n", strerror(errno));
        exit(1);
    }

    printf("%s\n", ptr);
    close(fd);

    return 0;
}
