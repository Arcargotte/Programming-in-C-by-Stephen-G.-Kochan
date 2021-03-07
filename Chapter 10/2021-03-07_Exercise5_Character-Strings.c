#include <stdio.h>


int findString (char source[], char subString[])
{
    int index;
    int i, j = 0;

    for (index = 0; source[index] != '\0'; ++index)
    {
        i = index;
        
        while (source[i] == subString[j])
        {
            i++;
            j++;
        }

        if (subString[j] == '\0')
            return index;
        else
            j = 0;
    }

    return -1;
}

int main (void)
{
    int findString (char source[], char subString[]);
    char mystr1[] = "My house is green", mystr2[] = "o";

    printf("%i", findString(mystr1, mystr2));

    return 0;
}