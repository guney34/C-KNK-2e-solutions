// once you free p, p->next no longer exists

struct node *p = first;
while (p != NULL) {
    struct node *temp = p;
    p = p->next;
    free(temp);
}