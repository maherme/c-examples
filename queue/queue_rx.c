/*
 * For compiling this code you need to use -lrt option: "gcc -o queue_tx queue_tx.c -lrt"
 * Queues are created in /dev/mqueue directory.
 * For this code you can see the queue using "cat myMsgQueue" in /dev/mqueue directory.
 * Queues atributes are in /proc/sys/fs/mqueue directory.
 */
#include <mqueue.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 8192 

mqd_t mqdes;
char buf[BUFFER_SIZE];
int byte_nr;

int main(void){

    mqdes = mq_open("/myMsgQueue", O_RDONLY);

    byte_nr = mq_receive(mqdes, buf, BUFFER_SIZE, NULL);

    printf("Message received: \n %s \n Nr bytes: %d \n", buf, byte_nr);

    mq_close(mqdes);

    return 0;
}
