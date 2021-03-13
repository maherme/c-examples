#include <stdio.h>
#include <sys/inotify.h>
#include <unistd.h>

int main(void){

    int fd = 0;
    int wd = 0;
    char buf[200];

    fd = inotify_init();
    wd = inotify_add_watch(fd, "/home/maherme/Projects/examples/inotify", IN_CLOSE_WRITE);

    while(1){
        read(fd, buf, 200); /* Program execution will block here until an event happens */
        printf("File written is: %s \n", ((struct inotify_event*)buf)->name);
    }

    return 0;
}

