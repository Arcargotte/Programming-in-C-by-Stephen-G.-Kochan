// Program 10.1: Function to concatenate two strings of characters

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* 
void concat (char result[], const char str1[], int n1,
const char str2[], int n2)
{
    int i, j;
    // copy str1 to result

    for ( i = 0; i < n1; ++i )
        result[i] = str1[i];

    // copy str2 to result
    for ( j = 0; j < n2; ++j )
        result[n1 + j] = str2[j];
}

int main (void)
{
    void concat (char result[], const char str1[], int n1,
    const char str2[], int n2);
    const char s1[5] = { 'T', 'e', 's', 't', ' '};
    const char s2[6] = { 'w', 'o', 'r', 'k', 's', '.' };
    char s3[11];
    int i;
    
    concat (s3, s1, 5, s2, 6);
    
    for ( i = 0; i < 11; ++i )
        printf ("%c", s3[i]);

    printf ("\n");

    return 0;
}

// -----> Improved version <-----

int main (void)
{
    char str1[] = "Hello", str2[] = " World", result[12];
    
    printf("%s", strncat(str1, str2, 12));

    return 0;
}

*/
/* Program 10.2: Function to count the number of characters in a string

int stringLength (const char string[])
{
    int count = 0;

    while ( string[count] != '\0' )
        ++count;

    return count;
}

int main (void)
{
    int stringLength (const char string[]);

    const char word1[] = { 'a', 's', 't', 'e', 'r', '\0' };
    const char word1[] = { 'a', 's', 't', 'e', 'r', '\0' };
    const char word3[] = { 'a', 'w', 'e', '\0' };

    printf ("%i %i %i\n", stringLength (word1),
             stringLength (word2), stringLength (word3));

    return 0;
}

// -----> Improved version <-----

int main (void)
{
    const char word1[] = { 'a', 's', 't', 'e', 'r', '\0' };
    const char word2[] = { 'a', 's', 't', 'e', 'r', '\0' };
    const char word3[] = { 'a', 'w', 'e', '\0' };

    printf ("%i %i %i\n", strlen(word1),
            strlen(word2), strlen(word3));     

    return 0;
}
*/

// Program 10.4: Function to determine if two strings are equal

/*
bool equalStrings (const char s1[], const char s2[])
{
    int i = 0;
    bool areEqual;
    
    while ( s1[i] == s2 [i] && s1[i] != '\0' && s2[i] != '\0' )
        ++i;

    if ( s1[i] == '\0' && s2[i] == '\0' )
        areEqual = true;
    else
        areEqual = false;

    return areEqual;
}
int main (void)
{
    bool equalStrings (const char s1[], const char s2[]);

    const char stra[] = "string compare test";
    const char strb[] = "string";

    printf ("%i\n", equalStrings (stra, strb));
    printf ("%i\n", equalStrings (stra, stra));
    printf ("%i\n", equalStrings (strb, "string"));

    return 0;
}

// -----> Improved version <-----

int main (void)
{
    const char str1[] = "string compare test";
    const char str2[] = "string";

    printf("%i\n", strcmp(str1, str1));

    return 0;
}
*/

// Program 10.11: Function to convert a string to an integer

/*
int strToInt (const char string[])
{
    int i, intValue, result = 0;

    for ( i = 0; string[i] >= '0' && string[i] <= '9'; ++i )
    {
        intValue = string[i] - '0';
        result = result * 10 + intValue;
    }

    return result;
}

int main (void)
{
    int strToInt (const char string[]);

    printf ("%i\n", strToInt("245"));
    printf ("%i\n", strToInt("100") + 25);
    printf ("%i\n", strToInt("13x5"));

    return 0;
}

// -----> Improved version <-----

int main (void)
{
    printf ("%i\n", atoi("245"));
    printf ("%i\n", atoi("100") + 25);
    printf ("%i\n", atoi("13x5"));    

    return 0;
}

*/