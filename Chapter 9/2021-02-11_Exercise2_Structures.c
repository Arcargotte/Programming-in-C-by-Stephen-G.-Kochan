#include <stdio.h>

struct date 
{
    int day;
    int month;
    int year;
}dates[2]; 

void dateGenerator (struct date dates[2])
{
    printf("Type in start date in format dd/mm/yy: ");
    scanf("%i/%i/%i", &dates[0].day, &dates[0].month, &dates[0].year);
    printf("Type in end date in format dd/mm/yy: ");
    scanf("%i/%i/%i", &dates[1].day, &dates[1].month, &dates[1].year);
   
}

int f (struct date date)
{
    int year;

    if (date.month <= 2)
        year = date.year - 1;
    else
        year = date.year;

    return year;
}

int g (struct date date)
{
    int month;

    if (date.month <=2)
        month = date.month + 13;
    else
        month = date.month + 1;

    return month;
}

int centuryChecker(struct date dates[2])
{
    int adder = 0;

    if (((dates[0].month >= 3) && (dates[0].year >= 1800)) && ((dates[1].month <= 2) && (dates[1].year <= 1900)))
        adder = 1;
    else if (((dates[0].month >= 3) && (dates[0].year >= 1700)) && ((dates[1].month <= 2) && (dates[1].year <= 1800)))
        adder = 2;

    return adder;
}

int elapsedDayGenerator(struct date dates[2])
{
    int N1, N2, result;
    
    N1 = 1461 * f(dates[0]) / 4 + 153 * g(dates[0]) / 5 + dates[0].day;
    N2 = 1461 * f(dates[1]) / 4 + 153 * g(dates[1]) / 5 + dates[1].day;
    result = N2 - N1;

    return result + centuryChecker(dates);
}

int main (void) 
{
    dateGenerator(dates);
    printf("The number of days between %i/%i/%i and %i/%i/%i is %i", dates[0].day,
            dates[0].month, dates[0].year, dates[1].day, dates[1].month, dates[1].year, 
            elapsedDayGenerator(dates));

    return 0;
}