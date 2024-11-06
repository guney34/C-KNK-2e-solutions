#include "queueADT.h"
#include <stdio.h>
#include <stdlib.h>

struct queue_type {
    Item *contents;
    int front;
    int rear;
    int num_items;
    int size;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue queue_create(int size)
{
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Error in create: queue could not be created.");
    q->contents = malloc((size_t)size * sizeof(Item));
    q->front = 0;
    q->rear = 0;
    q->num_items = 0;
    q->size = size;
    return q;
}

void queue_destroy(Queue q)
{
    free(q->contents);
    free(q);
}

void queue_insert(Queue q, Item i)
{
    if (q->num_items == q->size)
        terminate("Error in insert: queue is full.");

    q->contents[q->rear++] = i;
    if (q->rear == q->size)
        q->rear = 0;
    ++q->num_items;
}

void queue_make_empty(Queue q)
{
    while (!queue_is_empty(q)) {
        queue_remove(q);
    }
}

Item queue_remove(Queue q)
{
    if (queue_is_empty(q))
        terminate("Error in remove: queue is empty.");

    Item ret_data = q->contents[q->front];
    if (++q->front == q->size)
        q->front = 0;
    --q->num_items;
    return ret_data;
}

Item queue_get_first(Queue q)
{
    if (queue_is_empty(q))
        terminate("Error in get: queue is empty.");
    return q->contents[q->front];
}

Item queue_get_last(Queue q)
{
    if (queue_is_empty(q))
        terminate("Error in get: queue is empty.");
    if (q->rear == 0)
        return q->contents[q->size-1];
    return q->contents[q->rear-1];
}

bool queue_is_empty(Queue q)
{
    return q->num_items == 0;
}