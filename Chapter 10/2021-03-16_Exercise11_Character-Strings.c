/*
 * Extend the strToInt function from Program 10.11 so that if the first character of 
 * the string is a minus sign, the value that follows is taken as a negative number.
 * 
 */

// Function to convert a string to an integer

#include <stdio.h>
#include <stdbool.h>

int strToInt (const char string[])
{
    int i = 0, intValue, result = 0;
    bool flag = false;

    if (string[0] == '-')
    {
        flag = true;
        i++;
    }

    for (; string[i] >= '0' && string[i] <= '9'; ++i )
    {
        intValue = string[i] - '0';
        result = result * 10 + intValue;
    }

    if (flag)
        result = -(result);

    return result;
}

int main (void)
{
    int strToInt (const char string[]);

    printf ("%i\n", strToInt("-245"));
    printf ("%i\n", strToInt("100") - 225);
    printf ("%i\n", strToInt("xxx"));

    return 0;
}
