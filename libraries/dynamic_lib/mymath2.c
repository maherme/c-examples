#include <stdio.h>
#include "mymath2.h"

int square(int a){
    return a*a;
}

int cube(int a){
    return a*a*a;
}

int factorial(int a){

    int i = 0;
    int fact = 1;

    if(a < 0){
        printf("Error: returning 0, factorial of a negative number does not exist\n");
        fact = 0;
    }
    else{
        for(i = 1; i <= a; i++){
            fact *= i;
        }
    }

    return fact;
}
