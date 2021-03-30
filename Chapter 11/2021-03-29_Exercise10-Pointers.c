/*
 * Rewrite the compareStrings function from Chapter 10 to use character pointers
 * instead of arrays.
 */

#include <stdio.h>

int compareStrings (const char *s1, const char *s2)
{
    int i = 0, answer;

    while ( *s1 == *s2 && *s1 != '\0'&& *s2 != '\0' )  { // It can be shortened! (*s1++ != '\0') ...
        ++s1;
        ++s2;
    }

    if ( *s1 < *s2 )
        answer = -1; /* s1 < s2 */
    else if ( *s1 == *s2 )
        answer = 0; /* s1 == s2 */
    else
        answer = 1; /* s1 > s2 */

    return answer;
}

int main (void)
{
    char first[] = "zioty";
    char second[] = "yucca";

    printf("%i", compareStrings(first, second));

    return 0;
}