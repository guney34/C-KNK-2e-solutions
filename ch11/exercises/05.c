void split_time(long total_sec, int *hr, int *min, int *sec)
{
    *sec = total_sec % 60;
    *min = (total_sec / 60) % 60;
    *hr = (total_sec / 60) / 60;
}