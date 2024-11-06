void delete_from_list(struct node **list, int n)
{
    while (*list != NULL) {
        if ((*list)->value == n) {
            struct node *temp = *list;
            *list = (*list)->next;
            free(temp);
            break;
        }
        list = &(*list)->next;
    }
}