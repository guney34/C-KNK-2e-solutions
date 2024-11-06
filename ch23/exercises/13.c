int count_words(char *sentence)
{
    int count = 0;
    for (char *p = strtok(sentence, " \t\n\v\f\r"); p; p = strtok(NULL, " \t\n\v\f\r"))
        ++count;
    return count;
}