// Does not work if the new node should go to the beginning or end of the list.

// To fix the function for cases where the node belongs to the end, the while loop needs to
// check if 'cur' is a null pointer before dereferencing it.

// For the other case, the function fails because 'prev' is a null pointer and gets dereferenced.
// The function needs check if prev is NULL and if it is, it should make new_node the first node
// and return it.


struct node *insert_into_ordered_list(struct node *list, struct node *new_node)
{
    struct node *cur = list, *prev = NULL;
    while (cur != NULL && cur->value <= new_node->value) {
        prev = cur;
        cur = cur->next;
    }
    if (prev == NULL) {
        new_node->next = list;
        return new_node;
    } else {
        prev->next = new_node;
        new_node->next = cur;
        return list;
    }
}