/**
 * @file LinkedListForEach.c
 * @author Julhio Cesar Navas
 * @brief 
 * @version 0.1
 * @date 2020-09-08
 * 
 * @copyright Instituto Tecnológico de Aeronáutica. Copyright (c) 2020
 * 
 */

#include <stdio.h>

typedef struct list_node list_node;
struct list_node {
    list_node *next;
    void *data;
};

#define FOR_EACH(item, list) \
    for (list_node *(item) = (list); (item); (item) = (item)->next)

int
main(int argc, char *argv[])
{
    list_node list[] = {
        { .next = &list[1], .data = "test 1" },
        { .next = &list[2], .data = "test 2" },
        { .next = NULL,     .data = "test 3" }
    };

    FOR_EACH(item, list)
        puts((char *) item->data);

    return 0;
}