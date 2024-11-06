int day_of_year(int day, int month, int year)
{
    int result = day;
    switch(month) {
        case 12: result += 30; [[fallthrough]];
        case 11: result += 31; [[fallthrough]];
        case 10: result += 30; [[fallthrough]];
        case 9:  result += 31; [[fallthrough]];
        case 8:  result += 31; [[fallthrough]];
        case 7:  result += 30; [[fallthrough]];
        case 6:  result += 31; [[fallthrough]];
        case 5:  result += 30; [[fallthrough]];
        case 4:  result += 31; [[fallthrough]];
        case 3:  result += 28 + !(year % 4);  [[fallthrough]];
        case 2:  result += 31;
    }
    return result;
}