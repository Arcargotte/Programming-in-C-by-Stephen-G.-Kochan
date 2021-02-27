#include <stdio.h>

struct date 
{
    int day;
    int month;
    int year;
};

struct date gMyDate;


void dateGenerator (void)
{
    printf("Type in start date in format dd/mm/yy: ");
    scanf("%i/%i/%i", &gMyDate.day, &gMyDate.month, &gMyDate.year);   
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

    if (date.month <= 2)
        month = date.month + 13;
    else
        month = date.month + 1;

    return month;
}

void weekDay (struct date date)
{
    int day, N;

    N = 1461 * f(date) / 4 + 153 * g(date) / 5 + date.day;
    day = (N - 621049) % 7;

    switch (day)
    {
        case 0:
            printf("Sunday");
            break;
        case 1:
            printf("Monday");
            break;
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break; 
        case 6:
            printf("Saturday");
            break;
        default:
            printf("None");
            break;
    }
}


int main (void) 
{
    void dateGenerator (void);
    void weekDay (struct date date);


    dateGenerator();
    printf("The date %i/%i/%i falls on ", gMyDate.day, gMyDate.month, gMyDate.year);
    weekDay(gMyDate);

    return 0;
}