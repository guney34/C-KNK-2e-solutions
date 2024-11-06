#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define QUEUE_SIZE 100

typedef int Item;

typedef struct {
    int contents[QUEUE_SIZE];
    int front;
    int rear;
    int num_items;
} Queue;

void queue_insert(Queue *q, Item i);
Item queue_remove(Queue *q);
Item queue_get_first(Queue *q);
Item queue_get_last(Queue *q);
bool queue_is_empty(Queue *q);

#endif