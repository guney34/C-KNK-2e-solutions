//It's not possible, without modifying the string (or a copy), because strrchr has to first search for a null-terminating character.
//Therefore, repeated calls of strrchr, will just go to the end of the string and always find the same character.

//You can replace the matched character will NUL, after each call of strrchr, to find all occurances of that character.

//Example that copies str first:

void test_strrchr(const char *str, int ch)
{
    char cpy[strlen(str) + 1]; //create copy of str
    strcpy(cpy, str);

    char *p = strrchr(cpy, ch);
    while (p) {
        printf("found at index: %td\n", p-cpy);
        *p = '\0'; // replace the found character with NUL
        p = strrchr(cpy, ch);
    }
}