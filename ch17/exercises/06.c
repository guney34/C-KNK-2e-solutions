struct node* delete_from_list(struct node *list, int n)
{
    struct node **ptr = &list;
    while (*ptr != NULL) {
        if ((*ptr)->value == n) {
            struct node *temp = (*ptr)->next;
            free(*ptr);
            *ptr = temp;
            break;
        }
        ptr = &((*ptr)->next);
    }
    return list;
}