#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int printf(const char* format, ...){

    va_list args;
    int done;

    va_start(args, format);
    done = vfprintf(stdout, format, args);
    va_end(args);

    return done;
}

int main(){

    printf("Something we don't want to say.\n");
    printf("maherme says, \"Hello World\"\n");

    return 0;
}
