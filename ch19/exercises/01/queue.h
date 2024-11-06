#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int Item;

void queue_insert(Item i);
Item queue_remove(void);
Item queue_get_first(void);
Item queue_get_last(void);
bool queue_is_empty(void);

#endif