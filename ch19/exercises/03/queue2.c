#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct node {
    Item data;
    struct node *next;
};

static struct node *queue_front = NULL;
static struct node *queue_rear = NULL;

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void queue_insert(Item i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in insert: failed to allocate memory");

    new_node->data = i;
    new_node->next = NULL;

    if (queue_is_empty())
        queue_front = new_node;
    else
        queue_rear->next = new_node;
    queue_rear = new_node;
}

Item queue_remove(void)
{
    if (queue_is_empty())
        terminate("Error in remove: queue is empty.");

    Item ret_data = queue_front->data;
    struct node *temp = queue_front;
    queue_front = queue_front->next;

    if (queue_front == NULL)
        queue_rear = NULL;
        
    free(temp);
    return ret_data;
}

Item queue_get_first(void)
{
    if (queue_is_empty())
        terminate("Error in remove: queue is empty.");
    return queue_front->data;
}

Item queue_get_last(void)
{
    if (queue_is_empty())
        terminate("Error in remove: queue is empty.");
    return queue_rear->data;
}

bool queue_is_empty(void)
{
    return queue_rear == NULL || queue_front == NULL;
}