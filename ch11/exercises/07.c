void split_date(int day_of_year, int year, int *month, int *day)
{
    int days_in_month[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (year % 4 == 0)
        ++days_in_month[1]; 

    for (int i = 0; i < 12; ++i) {
        if (day_of_year < days_in_month[i]) {
            *month = i + 1;
            break;
        }
        day_of_year -= days_in_month[i];
    }
    *day = day_of_year;
}