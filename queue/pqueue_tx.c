/*
 * For compiling this code you need to use "gcc -o pqueue_tx pqueue_tx.c -lrt".
 * The queue will be created in /dev/mqueue directory.
 */
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

mqd_t mqdes;

int main(int argc, char *argv[]){

    if((mqdes = mq_open(argv[1], O_WRONLY|O_CREAT, 0660, NULL)) == -1){
        printf("error, queue could not be created\n");
        exit(1);
    }

    if(mq_send(mqdes, argv[2], strlen(argv[2]) + 1, atoi(argv[3])) == -1){
        printf("error, mq_send could not be completed\n");
        exit(1);
    }

    if(mq_close(mqdes) == -1){
        printf("error, queue could not be closed\n");
        exit(1);
    }

    return 0;
}
