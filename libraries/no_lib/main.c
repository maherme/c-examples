#include <stdio.h>
#include "mymath.h"
#include "mymath2.h"


int main(){

    int a = 9;
    int b = 2;

    printf("%d + %d = %d\n", a, b, sum(a, b));
    printf("%d - %d = %d\n", a, b, sub(a, b));
    printf("%d * %d = %d\n", a, b, mult(a, b));
    printf("%d / %d = %.2f\n", a, b, div(a, b));
    printf("square of %d is %d\n", a, square(a));
    printf("cube of %d is %d\n", a, cube(a));
    printf("factorial of %d is %d\n", a, factorial(a));

    return 0;
}
