#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define QUEUE_SIZE 100

static int queue_front = 0;
static int queue_rear = 0;
static int queue_num_items = 0;

static Item queue[QUEUE_SIZE] = {0};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void queue_insert(Item i)
{
    if (queue_num_items == QUEUE_SIZE)
        terminate("Error in insert: queue is full.");

    queue[queue_rear++] = i;
    if (queue_rear == QUEUE_SIZE)
        queue_rear = 0;
    ++queue_num_items;
}

Item queue_remove(void)
{
    if (queue_is_empty())
        terminate("Error in remove: queue is empty.");

    Item ret_data = queue[queue_front];
    if (++queue_front == QUEUE_SIZE)
        queue_front = 0;
    --queue_num_items;
    return ret_data;
}

Item queue_get_first(void)
{
    if (queue_is_empty())
        terminate("Error in get: queue is empty.");
    return queue[queue_front];
}

Item queue_get_last(void)
{
    if (queue_is_empty())
        terminate("Error in get: queue is empty.");
    if (queue_rear == 0)
        return queue[QUEUE_SIZE-1];
    return queue[queue_rear-1];
}

bool queue_is_empty(void)
{
    return queue_num_items == 0;
}