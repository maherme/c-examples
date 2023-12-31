/*
 * This program is an example of usage for the glthreads library.
 * The program creates a particular structure to store information about the employees, instances three
 * structures and adds to the glue list. After this it prints the information in the list, it removes
 * the node in the middle and it prints the list again.
 */

#include "glthreads.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct
{
    char name[32];
    unsigned int salary;
    char designation[32];
    unsigned int employ_id;
    glthread_node_t glnode;
} employ_t;

static void
create_employ(employ_t *employ, employ_t const *employ_handler)
{
    strncpy(employ->name, employ_handler->name, strlen(employ_handler->name) + 1);
    employ->salary = employ_handler->salary;
    strncpy(employ->designation, employ_handler->designation, strlen(employ_handler->designation) + 1);
    employ->employ_id = employ_handler->employ_id;
    glthread_node_init(&employ->glnode);
}

static void
print_employ(employ_t *employ)
{
    printf("\tName: %s\n", employ->name);
    printf("\tSalary: %d\n", employ->salary);
    printf("\tDesignation: %s\n", employ->designation);
    printf("\tEmploy ID: %d\n", employ->employ_id);
    printf("---------------------------------------\n");
}

static void
print_list(glthread_t* employ_list)
{
    employ_t *tmp;

    printf("\n# Printing nodes information:\n\n");
    printf("---------------------------------------\n");
    /* Iterate over the list and print element information */
    GLTHREAD_ITERATE_BEGIN(employ_list, employ_t, tmp){
        print_employ(tmp);
    }GLTHREAD_ITERATE_END;
}

int
main(int argc, char **argv)
{
    employ_t employ_1, employ_2, employ_3;
    glthread_t employ_list;

    employ_t employ_mark = {
        .name = {"Makr"},
        .salary = 50000,
        .designation = {"Human Resources"},
        .employ_id = 1,
    };

    employ_t employ_hellen = {
        .name = {"Hellen"},
        .salary = 150000,
        .designation = {"Manager"},
        .employ_id = 2,
    };

    employ_t employ_andrew = {
        .name = {"Andrew"},
        .salary = 120000,
        .designation = {"Developer"},
        .employ_id = 3,
    };

    create_employ(&employ_1, &employ_mark);
    create_employ(&employ_2, &employ_hellen);
    create_employ(&employ_3, &employ_andrew);

    glthread_init(&employ_list, offsetof(employ_t, glnode));

    glthread_add(&employ_list, &employ_1.glnode);
    glthread_add(&employ_list, &employ_2.glnode);
    glthread_add(&employ_list, &employ_3.glnode);

    print_list(&employ_list);

    printf("\n# Removing node 2\n\n");
    glthread_remove(&employ_list, &employ_2.glnode);

    print_list(&employ_list);

    exit(EXIT_SUCCESS);
}
