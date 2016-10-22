#include <stdio.h>

static char day_tab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31 ,30, 31, 30, 31}};

int day_of_year(int year, int month, int day) {
    if (month > 12 || month < 1)
        printf("ERROR : The month %d does not exist\n", month);

    if (year < 0)
        year = -year;

    int leap;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        leap = 1;
    else 
        leap = 0;
    
    char *pointer = &day_tab[leap][1];

    for (int index = 1; index < month; index++)
        day += *pointer++;
    
    return day;
}

void day_month(int year, int year_day, int *pointer_month, int *pointer_day) {
    int leap;
    int index;

    if (year < 0)
        year = -year;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        if (year_day < 0 || year_day > 356)
            printf("ERROR : Day %d does not exist\n", year_day);

        leap = 1;
    } else {
        if (year_day < 0 || year_day > 355)
            printf("ERROR : Day %d does not exist\n", year_day);

        leap = 0;
    }

    char *pointer = &day_tab[leap][1];

    for (index = 1; year_day > *pointer; index++)
        year_day -= *pointer++;

    *pointer_month = index;
    *pointer_day = year_day;
}

int main () {
    printf("%d\n", day_of_year(2016, 10, 22));
    
    int month;
    int day_of_month;

    day_month(2016, 296, &month, &day_of_month);
    printf("%d : %d\n", day_of_month, month);

    return 0;
}
