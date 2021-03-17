/*
 * Write a function called intToStr that converts an integer value into a character
 * string. Be certain the function handles negative integers properly
 * 
 */

#include <stdio.h>

char gArray[40];

int main (void)
{
    int myInteger = 343434555;
    void intToStr (int integer);

    intToStr(myInteger);
    
    return 0;
}

static int i = 0;

void intToStr (int integer)
{
    printf("%d\n", integer);

    int quotient = integer / 10, modulo = integer % 10;

    if (quotient == 0)
    {
      gArray[i] = integer + '0';
    }  
    else 
    {
        intToStr(quotient);
        i++;
        gArray[i] = modulo + '0';
    }
}