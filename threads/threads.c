/*
 * In order to compile this code you need to use: "gcc -o threads threads.c -pthread"
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

static void *thread_routine(void *arg){

    int nr_lines = *((int*)arg);
    int fd = 0;
    char buf[] = "New line.\n";

    printf("The thread starts to execute ...\n");
    for(int i = 0; i<nr_lines; i++){
        if((fd = open("/home/maherme/Projects/examples/threads/file", O_WRONLY|O_APPEND)) < 0){
            perror("Error: the file could not be opened.\n");
        }
        else{
            write(fd, buf, sizeof(buf)-1);
            close(fd);
        }
    }
}

int main(int argc, char *argv[]){

    int value = 0;
    pthread_t thread1;

    if(argc == 2){
        value = atoi(argv[1]);
    }
    else{
        perror("Wrong number of arguments, number of line for writting needed as argument.\n");
        return -1;
    }

    if(pthread_create(&thread1, NULL, thread_routine, &value) != 0){
        return -1;
    }

    pthread_join(thread1, NULL);

    return 0;
}
