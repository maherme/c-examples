/*
 * This program creates a child process.
 * You can see the process using "ps lf" in terminal.
 * You can kill a process using "kill -9 <PID>" in terminal.
 * If you kill the parent process the child process will get a new parent process.
 * You can know details about a process using "ps lp <PID>" in terminal.
 * If you kill the child process, this become a zombie. See using "ps lf".
 */
#include <unistd.h>
#include <stdio.h>

int var = 22;

int main(void){

    pid_t pidC;

    printf("** proc. PID = %d starts ** \n", getpid());
    pidC = fork();

    printf("proc. PID = %d, pidC = %d executing \n", getpid(), pidC);

    if(pidC > 0){
        var = 44;
    }
    else if(pidC == 0){
        var = 33;
    }
    else{ /* error */
    }

    while(1){
        sleep(2);
        printf("proc. PID = %d, var = %d executing \n", getpid(), var);
    }

    return 0;
}
