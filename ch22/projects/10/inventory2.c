#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL;

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void restore(void);

int main(void)
{
    char code;

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')
            ;
        switch (code) {
            case 'i': insert(); break;
            case 's': search(); break;
            case 'u': update(); break;
            case 'p': print();  break;
            case 'd': dump(); break;
            case 'r': restore(); break;
            case 'q': return 0;
            default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

struct part *find_part(int number)
{
    struct part *p;

    for (p = inventory; p != NULL && number > p->number; p = p->next)
        ;
    if (p != NULL && number == p->number)
        return p;
    return NULL;
}

void insert(void)
{
    struct part *cur, *prev, *new_node;

    new_node = malloc(sizeof(struct part));
    if (new_node == NULL) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    for (cur = inventory, prev = NULL;
         cur != NULL && new_node->number > cur->number;
         prev = cur, cur = cur->next)
        ;
    if (cur != NULL && new_node->number == cur->number) {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next = cur;
    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
}

void search(void)
{
    int number;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    } else
        printf("Part not found.\n");
}

void update(void)
{
    int number, change;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        p->on_hand += change;
    } else
        printf("Part not found.\n");
}

void print(void)
{
    struct part *p;

    printf("Part Number   Part Name                  Quantity on Hand\n");
    for (p = inventory; p != NULL; p = p->next)
        printf("%7d       %-25s%11d\n", p->number, p->name, p->on_hand);
}

void dump(void)
{
    char filename[FILENAME_MAX];
    printf("Enter name of output file: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Failed to open %s\n", filename);
        return;
    }

    //write struct members individually due to padding
    for (struct part *p = inventory; p != NULL; p = p->next) {
        fwrite(&p->number, sizeof(p->number), 1, fp);
        fwrite(&p->name, sizeof(p->name), 1, fp);
        fwrite(&p->on_hand, sizeof(p->on_hand), 1, fp);
    }

    fclose(fp);
    return;
}

void restore(void)
{
    char filename[FILENAME_MAX];
    printf("Enter name of input file: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Failed to open %s\n", filename);
        return;
    }
    
    while (inventory != NULL) { //delete all nodes
        struct part *temp = inventory;
        inventory = inventory->next;
        free(temp); 
    }

    for (struct part **p = &inventory;;) {
        *p = malloc(sizeof(struct part));
        if (*p == NULL) {
            printf("Failed to allocate memory\n");
            break;
        }

        (*p)->next = NULL;

        if (fread(&(*p)->number, sizeof((*p)->number), 1, fp) != 1) { //done reading
            free(*p);
            *p = NULL;
            break;
        }

        if (fread(&(*p)->name, sizeof((*p)->name), 1, fp) != 1) { //corrupt data
            printf("Corrupt data or incorrect format; restore didn't complete\n");
            free(*p);
            *p = NULL;
            break;
        }

        if (fread((&(*p)->on_hand), sizeof((*p)->on_hand), 1, fp) != 1) { //corrupt data
            printf("Corrupt data or incorrect format; restore didn't complete\n");
            free(*p);
            *p = NULL;
            break;
        }

        p = &(*p)->next;
    }    

    fclose(fp);
    return;
}