#include "routing_table.h"
#include "threated_publisher.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

static routing_table_t publisher_routing_table;

int main(int argc, char **argv)
{
    routing_table_init(&publisher_routing_table);
#if 0
    create_subscriber_thread(1);
    sleep(1);

    create_subscriber_thread(2);
    sleep(1);

    create_subscriber_thread(3);
    sleep(1);
#endif
    create_publisher_thread(&publisher_routing_table);
    printf("Publisher thread created\n");

    pthread_exit(EXIT_SUCCESS);
}
