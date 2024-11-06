#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void read_word(int counts[26])
{
    char ch;
    while((ch = (char)getchar()) != '\n') {
        if (!isalpha(ch)) 
            continue;
        ++counts[tolower(ch) - 'a'];
    }
}

bool equal_array(int a[26], int b[26])
{
    for (int i = 0; i < 26; ++i) {
        if (a[i] != b[i]) 
            return false;
    }
    return true;
}

int main(void)
{
    int A[26] = {0};
    int B[26] = {0};

    printf("Enter first word: ");
    read_word(A);
    printf("Enter second word: ");
    read_word(B);

    printf("The words are ");
    if (equal_array(A, B)) 
        printf("anagrams.");
    else 
        printf("not anagrams.");
}