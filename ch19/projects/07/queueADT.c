#include "queueADT.h"
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

struct node {
    Item data;
    struct node *next;
};

struct queue_type {
    struct node *front;
    struct node *rear;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue queue_create(void)
{
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Error in create: queue could not be created.");
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void queue_destroy(Queue q)
{
    queue_make_empty(q);
    free(q);
}

void queue_insert(Queue q, Item i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in insert: failed to allocate memory");

    new_node->data = i;
    new_node->next = NULL;

    if (queue_is_empty(q))
        q->front = new_node;
    else
        q->rear->next = new_node;
    q->rear = new_node;
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

    Item ret_data = q->front->data;
    struct node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;
        
    free(temp);
    return ret_data;
}

Item queue_get_first(Queue q)
{
    if (queue_is_empty(q))
        terminate("Error in remove: queue is empty.");
    return q->front->data;
}

Item queue_get_last(Queue q)
{
    if (queue_is_empty(q))
        terminate("Error in remove: queue is empty.");
    return q->rear->data;
}

bool queue_is_empty(Queue q)
{
    return q->rear == NULL || q->front == NULL;
}