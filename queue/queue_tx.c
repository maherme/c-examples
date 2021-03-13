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

mqd_t mqdes;
char buf[100];

int main(void){

    mqdes = mq_open("/myMsgQueue", O_WRONLY|O_CREAT, 0664, NULL);

    printf("Waiting for text ... \n");

    scanf("%s", buf);

    mq_send(mqdes, buf, strlen(buf) + 1, 0);

    mq_close(mqdes);

    return 0;
}
