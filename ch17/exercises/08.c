struct node {
    int value;
    struct node *next;
};

struct node *top;

void make_empty(void)
{
    while (top != NULL) {
        struct node *temp = top;
        top = top->next;
        free(temp);
    }
}

bool is_empty(void)
{
    return top == NULL;
}

bool push(int n)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        return false;

    new_node->value = n;
    new_node->next = top;
    top = new_node;
    return true;
}

int pop(void)
{
    if (is_empty()) {
        printf("stack underflow");
        exit(EXIT_FAILURE);
    }
    int n = top->value;
    struct node *temp = top;
    top = top->next;
    free(temp);
    return n;
}