#include <stdio.h>

#include <stdio.h>

struct date {
    int day;
    int month;
    int year;
};

struct time {
    int hour;
    int minutes;
    int seconds;
};

struct dateAndTime {
    struct date sdate;
    struct time stime;
};

struct month {
    int number_Of_Days;
    char name[3];
};

const struct month months[12] ={ 
    { 31, {'J', 'a', 'n'} }, { 28, {'F', 'e', 'b'} },
    { 31, {'M', 'a', 'r'} }, { 30, {'A', 'p', 'r'} },
    { 31, {'M', 'a', 'y'} }, { 30, {'J', 'u', 'n'} },
    { 31, {'J', 'u', 'l'} }, { 31, {'A', 'u', 'g'} },
    { 30, {'S', 'e', 'p'} }, { 31, {'O', 'c', 't'} },
    { 30, {'N', 'o', 'v'} }, { 31, {'D', 'e', 'c'} } 
    };

struct dateAndTime askForDateAndTime (void)
{
    struct dateAndTime event;

    printf("Type in a date in format dd/mm/yy: ");
    scanf("%i/%i/%i", &event.sdate.day, &event.sdate.month, &event.sdate.year);
    printf("Type in a time in military format hh:mm:ss: ");
    scanf("%i:%i:%i", &event.stime.hour, &event.stime.minutes, &event.stime.seconds);

    return event;
}

struct dateAndTime timeUpdate (struct dateAndTime now)
{
    ++now.stime.seconds;
    if ( now.stime.seconds == 60 ) // next minute
    { 
        now.stime.seconds = 0;
        ++now.stime.minutes;

        if ( now.stime.minutes == 60 ) // next hour
        { 
            now.stime.minutes = 0;
            ++now.stime.hour;

            if ( now.stime.hour == 24 ) 
            {
                now.stime.hour = 0;
                ++now.sdate.day;

                if (now.sdate.day > months[now.sdate.month - 1].number_Of_Days)
                {
                    now.sdate.day = 1;
                    ++now.sdate.month;

                    if (now.sdate.month > 12)
                    {
                        ++now.sdate.year;
                        now.sdate.month = 1;
                    }
                }
            }
        }
    }
    return now;
}

int main (void)
{
    struct dateAndTime timeUpdate (struct dateAndTime now), askForDateAndTime (void);
    struct dateAndTime myDateAndTime, myDateAndTimeUpdated;

    myDateAndTime = askForDateAndTime();
    myDateAndTimeUpdated = timeUpdate(myDateAndTime);

    printf("Date: %i/%i/%i\nTime: %i:%i:%i\n", myDateAndTime.sdate.day, myDateAndTime.sdate.month, 
            myDateAndTime.sdate.year, myDateAndTime.stime.hour, myDateAndTime.stime.minutes, 
            myDateAndTime.stime.seconds);
    printf("Updated date: %i/%i/%i\nUpdated Time: %i:%i:%i\n", myDateAndTimeUpdated.sdate.day, 
            myDateAndTimeUpdated.sdate.month, myDateAndTimeUpdated.sdate.year, myDateAndTimeUpdated.stime.hour, 
            myDateAndTimeUpdated.stime.minutes, myDateAndTimeUpdated.stime.seconds);

    return 0;
}