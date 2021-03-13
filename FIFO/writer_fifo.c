/*
 * Writter function for writing in a FIFO (/tmp/my_fifo).
 * This program will stop in write function waiting for a process to connect to the FIFO.
 */
#include <sys/stat.h> /* Needed for using mkfifo() */
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void){

    int fd = 0;
    char buf[] = "message ... ";

    mkfifo("/tmp/my_fifo", 0666);

    if((fd = open("/tmp/my_fifo", O_WRONLY)) < 0){
        perror("FIFO could not be created");
    }
    else{
        write(fd, buf, sizeof(buf));
        close(fd);
    }

    return 0;
}
