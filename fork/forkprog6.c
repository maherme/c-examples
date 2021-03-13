/*
 * This code uses pipe() function to comunicate a parent and child process.
 * pipe() function create a fd for reading (fd[0]) and a fd for writing (fd[1]).
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){

    int fd[2];
    pid_t pidC;
    char buf[10];
    int num;

    pipe(fd);

    pidC = fork();

    switch(pidC){
        case 0: /* child */
            close(fd[0]); /* close read descriptor */
            write(fd[1], "abcde", 5);
            close(fd[1]);
            exit(0);
            break;
        case -1:
            /* error */
            break;
        default: /* parent */
            close(fd[1]); /* close write descriptor */
            num = read(fd[0], buf, sizeof(buf));
            printf("Parent has read %d bytes: %s \n", num, buf);
            close(fd[0]);
            break;
    }

    return 0;
}
