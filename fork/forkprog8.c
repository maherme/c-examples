/*
 * This code implements the command line "ls -l | grep k | wc -l" using
 * pipe and fork functions.
 *
 *  child1                        child2               child3
 *  ls -l                         grep u                        wc -l
 *
 *  stdout  ---------------  stdin     stdout  ---------------  stdin
 *                pipe1                             pipe2
 *  fd1[1]  ---------------  fd1[0]    fd2[1]  ---------------  fd2[0]
 *
 * Take into account that child processes will inherit the file descriptors
 * created by theis parents.
 */
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define READ_END 0
#define WRITE_END 1

int main(int argc, char *argv[]){

    int fd1[2], fd2[2];
    int status, pid;

    pipe(fd1);

    pid = fork();

    if(pid == 0){ /* child 1 */
        close(fd1[READ_END]);

        dup2(fd1[WRITE_END], STDOUT_FILENO);
        close(fd1[WRITE_END]);

        execlp("/bin/ls", "ls", "-l", NULL);
    }
    else{ /* parent */
        close(fd1[WRITE_END]);
        pipe(fd2);
        pid = fork();

        if(pid == 0){ /* child 2 */
            close(fd2[READ_END]);

            dup2(fd1[READ_END], STDIN_FILENO);
            close(fd1[READ_END]);

            dup2(fd2[WRITE_END], STDOUT_FILENO);
            close(fd2[WRITE_END]);

            execlp("/bin/grep", "grep", "k", NULL);
        }
        else{ /* parent */
            close(fd1[READ_END]);
            close(fd2[WRITE_END]);

            pid = fork();

            if(pid == 0){ /* child 3 */
                dup2(fd2[READ_END], STDIN_FILENO);
                close(fd2[READ_END]);

                execlp("/usr/bin/wc", "wc", "-l", NULL);
            }
        }
    }

    close(fd2[READ_END]);

    /* wait for each child */
    wait(&status);
    wait(&status);
    wait(&status);

    return 0;
}
