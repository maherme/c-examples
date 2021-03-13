/*
 * The idea under this code is read from a pipe when the writing descriptor
 * is closed, is this case, the reading descriptor receives a EOF and the
 * read function will return a 0.
 * If you change sleep(5); sentence for while(1){sleep(1);} you will see the
 * parent process does not finish due to read function never returns a 0. because
 * the fd for writing is not closed.
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){

    int fd[2];
    char buf[100];
    int num;

    pipe(fd);

    switch(fork()){
        case 0: /* child */
            close(fd[0]);
            write(fd[1], "abcde ...", 9);
            write(fd[1], "gfhij ...", 9);
            sleep(5);
            close(fd[1]);
            exit(0);
            break;
        case 1: /* error */
            break;
        default: /* parent */
            close(fd[1]);
            while((num = read(fd[0], buf, sizeof(buf))) > 0){
                buf[num] = 0;
                printf("Parent has received %d bytes, %s \n", num, buf);
            }
            printf("Parent is finishing ...\n");
            close(fd[0]);
            break;
    }

    return 0;
}
