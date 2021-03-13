/*
 * Function that waits until a number of bytes is passed by terminal and
 * reserves this amount of memory using malloc.
 * After reserving memory, fills the memory with 'z' character.
 */
#include <stdlib.h>
#include <stdio.h>

static void FillWithZ(char *ptr, unsigned int nr_bytes);

int main(void){

    unsigned int nr_bytes = 0;
    char *ptr = NULL;

    scanf("%ud", &nr_bytes);
    ptr = malloc(nr_bytes);

    if(ptr != NULL){
        FillWithZ(ptr, nr_bytes);
        free(ptr);
    }

    return 0;
}

static void FillWithZ(char *ptr, unsigned int nr_bytes){

    for(int i = 0; i < nr_bytes; i++){
        *ptr = 'z';
        ptr++;
    }
}
