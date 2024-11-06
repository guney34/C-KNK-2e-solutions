#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef int Item;
typedef struct queue_type *Queue;

Queue queue_create(int size);
void queue_destroy(Queue q);
void queue_insert(Queue q, Item i);
void queue_make_empty(Queue q);
Item queue_remove(Queue q);
Item queue_get_first(Queue q);
Item queue_get_last(Queue q);
bool queue_is_empty(Queue q);

#endif