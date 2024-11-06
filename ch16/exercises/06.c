struct time split_time(long total_seconds)
{
    struct time t;

    t.hours = total_seconds / 3600;
    t.minutes = (total_seconds % 3600) / 60;
    t.seconds = (total_seconds % 3600) % 60;
    return t;
}