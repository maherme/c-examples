/*
 * To compile this code you need to use "gcc -o pqueue_rx pqueue_rx.c -lrt".
 */
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

/* To know this value you need to check: "cat /proc/sys/fs/mqueue/msgsize_max". */
#define BUF_SIZE 8192

int main(int argc, char *argv[]){

    mqd_t mqdes;
    unsigned int prio;
    ssize_t byte_nr;

    char buf[BUF_SIZE];

    if((mqdes = mq_open(argv[1], O_RDONLY)) == -1){
        printf("error, queue could not be opened\n");
        exit(1);
    }

    if((byte_nr = mq_receive(mqdes, buf, BUF_SIZE, &prio)) == -1){
        printf("error in reception from queue\n");
        exit(1);
    }

    printf("Message: %s; Num Bytes: %d; Priority: %u\n", buf, (int)byte_nr, prio);

    mq_close(mqdes);

    return 0;
}
