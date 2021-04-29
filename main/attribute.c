#include <stdio.h>

/* Applying the constructor attribute to a function so that it is executed before main() */
void my_start_fun(void) __attribute__ ((constructor));

/* Applying the destructor attribute to a function so that it is executed after main() */
void my_end_fun(void) __attribute__ ((destructor));

void my_start_fun(void){
    printf("hello world!!!\n");
}

void my_end_fun(void){
    printf("good bye cruel world!!!\n");
}

int main(void){
    printf("this is the main function\n");
    return 0;
}
