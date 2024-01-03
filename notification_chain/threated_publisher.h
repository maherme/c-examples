#ifndef THREATED_PUBLISHER_H
#define THREATED_PUBLISHER_H

#include "routing_table.h"

void *
publisher_thread_fn(void *arg);

void
create_publisher_thread(routing_table_t *publisher_routing_table);

#endif /* THREATED_PUBLISHER_H */
