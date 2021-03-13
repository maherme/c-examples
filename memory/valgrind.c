/*
 * This code is created as example for using valgrind tool
 * to analyze memory leak.
 * You need to compile using "gcc -g -o exe_valgrind valgrind.c"
 * For using valgrind: "valgrind --leak-check=yes ./exe_valgrind"
 */
#include <stdlib.h>
#include <unistd.h>

char *ptr = NULL;

int main(void){
    
    for(int i = 0; i < 100; i++){
        ptr = malloc(100);
    }

    return 0;
}
