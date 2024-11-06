struct node *find_last(struct node *list, int n)
{
    struct node *temp = NULL;
    while (list != NULL) {
        if (list->value == n)
            temp = list;
        list = list->next;
    }
    return temp;
}