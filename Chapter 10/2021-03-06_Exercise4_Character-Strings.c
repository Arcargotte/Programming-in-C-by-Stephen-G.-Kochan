#include <stdio.h>
#include <string.h>

int main (void)
{
    const char *subString (const char source[], int start, int count, char result[]);
    int x = 3, y = 10;
    const char str1[] = "two words";
    char substr1[y];

    printf("%20s\n", subString(str1, x, y, substr1));

    return 0;
}

const char *subString (const char source[], int start, int count, char result[])
{
    int i = start, j;

    for (j = 0; (j < count && source[i] != '\0'); ++j)
    {
        result[j] = source[i];
       
        ++i;
    }

    result[j] = '\0';

    return result;
}