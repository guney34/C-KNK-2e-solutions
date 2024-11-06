#include <stdio.h>
#include <string.h>

#define NAME_LEN 100

void reverse_name(char *name)
{
    char *p = name;
    while (*p == ' ')
        ++p;
    char initial = *p;
    while (*p != ' ')
        ++p;
    while (*p == ' ')
        ++p;
    while (*p && *name)
        *name++ = *p++;
    
    *name++ = ',';
    *name++ = ' ';
    *name++ = initial;
    *name++ = '.';
    *name = '\0';
}

int main(void)
{
    char name[NAME_LEN+1];

    printf("Enter a first and last name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    reverse_name(name);
    printf("%s", name);
}