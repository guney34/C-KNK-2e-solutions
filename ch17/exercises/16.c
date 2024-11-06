int sum(int (*f)(int), int start, int end)
{
    int result = 0;
    for (; start <= end; ++start)
        result += f(start);
    return result;
}