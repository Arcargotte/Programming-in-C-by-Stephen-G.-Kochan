#include <stdio.h>

struct time
{
    int hh;
    int mm;
    int ss;
    int pastMidday;
} gTimes[2];

void setTimes (struct time times[2])
{
    for (int i = 0; i < 2; ++i)
    {
        printf("Set time%i with format hh:mm:ss and append ,1 (true) or ,0 (false) if it's past midday\n", i + 1);
        scanf("%i:%i:%i,%i", &times[i].hh, &times[i].mm, &times[i].ss, &times[i].pastMidday);
        printf("\n");
    }
}

void displayTimes (struct time times[2])
{
    for (int i = 0; i < 2; i++)
    {
        if (times[i].pastMidday)
            printf("%i:%i:%i p.m.\n", times[i].hh, times[i].mm, times[i].ss);
        else
            printf("%i:%i:%i a.m.\n", times[i].hh, times[i].mm, times[i].ss);
    }
}

int elapsedSeconds (struct time times[2])
{
    int nss = 0;

    if (times[0].ss > times[1].ss)
        nss = 60 - times[0].ss + times[1].ss;
    else if (times[0].ss < times[1].ss)
        nss = times[1].ss - times[0].ss;

    return nss;
}

int elapsedMinutes (struct time times[2])
{
    int nmm = 0;

    if (times[0].hh == times[1].hh)
        nmm = times[0].mm - times[1].mm;
    else if (times[0].mm > times[1].mm)
        nmm = 60 - times[0].mm + times[1].mm;
    else if (times[0].mm < times[1].mm)
        nmm = times[1].mm - times[0].mm;

    if (nmm < 0)
        nmm = - nmm;

    return nmm;
}

int elapsedHours (struct time times[2])
{
    int nhh;

    if ((times[0].pastMidday == times[1].pastMidday) && (times[0].hh > times[1].hh))
    { 
        printf("Assuming that start time is on previous day, the time between %i:%i:%i and %i:%i:%i is:\n",
                times[0].hh, times[0].mm, times[0].ss, times[1].hh, times[1].mm, times[1].ss);

        nhh = 24 - (times[0].hh - times[1].hh);
    }
    else if (times[0].pastMidday == times[1].pastMidday)
    {
        nhh = times[0].hh - times[1].hh;
    }

    else if (times[0].pastMidday)
    {
        times[0].hh = 12 - times[0].hh;
        nhh = times[0].hh + times[1].hh;
    }
    else if (times[1].pastMidday)
    {
        times[1].hh = times[1].hh + 12;
        nhh = times[1].hh - times[0].hh;
    }

    if (nhh < 0)
        nhh = - nhh;
    return nhh;
}

struct time elapsedTime (struct time times[2])
{
    int nss = elapsedSeconds(gTimes);
    int nmm = elapsedMinutes(gTimes);
    int nhh = elapsedHours(gTimes);

    if (times[0].ss == 59)
        nmm = nmm - 1;
    if (times[0].mm == 59)
        nhh = nhh - 1;

    struct time nElapsedTime = {.hh = nhh, .mm = nmm, .ss = nss};

    return nElapsedTime;
}

int main (void)
{
    void setTimes(struct time times[2]), displayTimes(struct time times[2]);
    int elapsedSeconds(struct time times[2]), elapsedMinutes(struct time times[2]), elapsedHours(struct time times[2]);
    struct time elapsedTime(struct time times[2]);

    setTimes(gTimes);
    displayTimes(gTimes);
    struct time new_elapsed_time = elapsedTime(gTimes);

    printf("\n%i hour, %i minute, %i second\n", new_elapsed_time.hh, new_elapsed_time.mm, new_elapsed_time.ss);

    return 0;
}