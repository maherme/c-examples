/*
 * This code use mmap function for writting a file passed as argument 1 into memory and
 * replaces all characters of type passed as argument 2 for characters of type passed as
 * argument 3.
 */
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    char *addr, *filename;
    int fd = 0;
    char seekchar, newchar;
    struct stat statbuf;

    if(argc == 4){
        filename = argv[1];
        seekchar = *argv[2];
        newchar = *argv[3];
    }
    else{
        printf("error, wrong argument number\n");
        exit(1);
    }

    if((fd = open(filename, O_RDWR)) == -1){
        printf("error, file could not be opened\n");
        exit(1);
    }

    if(fstat(fd, &statbuf) == -1){
        printf("error, fstat could not be completed\n");
        exit(1);
    }

    if((addr = mmap(NULL, statbuf.st_size, PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED){
        printf("error, mmap could not be completed\n");
        exit(1);
    }
    printf("Before modifying: \n%s\n", addr);

    for(size_t i = 0; i < statbuf.st_size; i++){
        if(addr[i] == seekchar){
            addr[i] = newchar;
        }
    }

    printf("Afer modifying: \n%s\n", addr);

    return 0;
}
