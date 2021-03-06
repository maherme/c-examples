#include <stdio.h>
#include <stdarg.h>

/* This function accepts whatever number of arguments, num is the number of arguments passed as ... */
void print_ints(int num, ...){

    va_list args;
    va_start(args, num); /* Initialize args to the beginning of the list */

    for(int i=0; i<num; i++){
        int value = va_arg(args, int); /* Return the next argument in the list pointed to by args */
        printf("%d: %d\n", i, value);
    }

    va_end(args); /* clean up */
}

int main(){

    print_ints(3, 24, 26, 312);
    print_ints(2, 256, 512);
    print_ints(7, 1, 2, 3, 4, 5, 6, 7);

    return 0;
}
