#include "threated_subscriber.h"
#include "routing_table.h"
#include "notification_chain.h"
#include "utilities.h"
#include <stdio.h>
#include <pthread.h>
#include <string.h>

#if 0
static void
test_callback(int client_id, void *arg, size_t arg_size, nfc_type_update_t nfc_op_code)
{
    printf("%s() client: %d, notified with operation code %s\n",
           __FUNCTION__, client_id, nfc_get_str_operation_code(nfc_op_code));
}
#endif

static void *
subscriber_thread_fn(void *arg)
{
    routing_table_entry_keys_t routing_table_entry_keys;

    memset(&routing_table_entry_keys, 0, sizeof(routing_table_entry_keys_t));
    strncpy(routing_table_entry_keys.dest, "122.1.1.1", sizeof(routing_table_entry_keys.dest));
    routing_table_entry_keys.mask = 32;
#if 0
    routing_table_register_for_notification(publisher_get_routing_table(),
                                            &routing_table_entry_keys,
                                            sizeof(routing_table_entry_keys_t),
                                            test_callback,
                                            (int)arg);
#endif
    return NULL;
}

void
create_subscriber_thread(int client_id)
{
    int s;

    pthread_attr_t attr;
    pthread_t subscriber_thread;

    s = pthread_attr_init(&attr);
    if(0 != s)
    {
        handle_error_en(s, "pthread_attr_init");
    }

    s = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if(0 != s)
    {
        handle_error_en(s, "pthread_attr_setdetachstate");
    }

    s = pthread_create(&subscriber_thread, &attr, subscriber_thread_fn, &client_id);
    if(0 != s)
    {
        handle_error_en(s, "pthread_create");
    }

    printf("Subscriber %d created\n", client_id);
}
