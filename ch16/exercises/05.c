// a)
int day_of_year(struct date d)
{
    int result = d.day;
    switch(d.month) {
        case 12: result += 30; [[fallthrough]];
        case 11: result += 31; [[fallthrough]];
        case 10: result += 30; [[fallthrough]];
        case 9:  result += 31; [[fallthrough]];
        case 8:  result += 31; [[fallthrough]];
        case 7:  result += 30; [[fallthrough]];
        case 6:  result += 31; [[fallthrough]];
        case 5:  result += 30; [[fallthrough]];
        case 4:  result += 31; [[fallthrough]];
        case 3:  result += 28 + !(d.year % 4);  [[fallthrough]];
        case 2:  result += 31;
    }
    return result;
}

// b)
int compare_dates(struct date d1, struct date d2)
{
    if (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day)
        return 0;

    if ((d1.year < d2.year) ||
        (d1.year == d2.year && d1.month < d2.month) ||
        (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day))
        return -1;

    return 1;
}