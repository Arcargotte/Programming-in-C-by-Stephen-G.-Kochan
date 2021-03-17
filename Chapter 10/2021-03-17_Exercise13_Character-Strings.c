/*
 * If c is a lowercase character, the expression
 * 
 *                                   c – 'a' + 'A'
 * 
 * produces the uppercase equivalent of c, assuming an ASCII character set.
 * Write a function called uppercase that converts all lowercase characters in a string
 * into their uppercase equivalents.
 */

#include <stdio.h>

int main (void)
{
    void uppercase (char string[]);
    char myString[] = "this is an All-lowercase String of C32haracters";

    uppercase(myString);

    printf("%s", myString);

    return 0;
}

void uppercase (char string[])
{
    char myChar;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if ( (string[i] >= 'a') && (string[i] <= 'z') )
        {
            myChar = string[i] - 'a' + 'A';
            string[i] = myChar;            
        }
    }
}