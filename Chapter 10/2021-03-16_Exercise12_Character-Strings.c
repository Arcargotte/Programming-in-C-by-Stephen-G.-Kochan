/*
 * Write a function called strToFloat that converts a character string into a floating point value. 
 * Have the function accept an optional leading minus sign. So, the call
 * 
 *                              strToFloat ("-867.6921");
 * 
 * should return the value –867.6921.
 */

#include <stdio.h>

int main (void)
{
    char myFloat[] = "-867.6921";
    double strToFloat (char myFloat[]);

    printf("%f", strToFloat(myFloat));

    return 0;
}

double strToFloat (char myFloat[])
{
    int i = 0, isNegative = 0, temp, decimal;
    double result;

    if (myFloat[i] == '-')
    {
        isNegative = 1;
        i++;
    }

    for (; myFloat[i] != '\0'; i++)
    {
        if (myFloat[i] != '.')
        {
            temp = myFloat[i] - '0';
            result = result * 10 + temp;   
        }
        else
            decimal = i;
    }

    for(int j = 1; j < (i - decimal); ++j)
        result /= 10;
    
    if (isNegative)
        result = - result;

    return result;
}

