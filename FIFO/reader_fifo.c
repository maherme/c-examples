/*
 * Reader function for reading in a FIFO (/tmp/my_fifo).
 */
#include <sys/stat.h> /* Needed for using mkfifo() */
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void){

    int fd = 0;
    int n = 0;
    char buf[1024];

    if((fd =open("/tmp/my_fifo", O_RDONLY)) < 0){
        perror("FIFO could not be opened");
    }
    else{
        n = read(fd, buf, sizeof(buf));
        printf("Nr message: %d \n", n);
        printf("RX message: %s \n", buf);
        close(fd); 
    }

    return 0;
}
