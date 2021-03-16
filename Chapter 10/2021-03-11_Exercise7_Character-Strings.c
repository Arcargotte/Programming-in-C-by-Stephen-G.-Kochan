/*
 * Write a function called insertString to insert one character string into another
 * string.The arguments to the function should consist of the source string, the string
 * to be inserted, and the position in the source string where the string is to be
 * inserted. So, the call
 * 
 *                     insertString (text, "per", 10);
 * 
 * with text as originally defined in the previous exercise, results in the character
 * string "per" being inserted inside text, beginning at text[10].Therefore, the
 * character string "the wrong person" is stored inside the text array after the
 * function returned
*/

#include <stdio.h>

int main (void)
{
    char text[] = "The wrong son";
    void insertString (char text[], char string[], int n);
    insertString(text, "per", 10);
    printf("%s", text);

    return 0;
}

void insertString (char text[], char string[], int position)
{
    int stringlength (char string[]);
    int len = stringlength (text);
    int insertionLen = stringlength (string);
    char buffer[len];
    int bposition = position, tposition = position;

    // buffer with all characters from text[position] up to '\0'
    for (int i = 0; bposition <= len; ++i)
    {
        buffer[i] = text[bposition];
        bposition++;
    }

    // insert new characters into the text
    for (int j = 0; j < insertionLen; j++)
    {
        text[tposition] = string[j];
        tposition++;
    }

    // insert buffer into the text with new characters
    for (int k = 0; buffer[k] != '\0'; ++k)
    {
        text[position + insertionLen] = buffer[k];
        ++position;
    }

    text[len + insertionLen] = '\0';
}


int stringlength (char string[])
{
    /*
     * Takes as argument a string of len i and returns an integer representing the number of elements
     * in the array including the null character '\0'
    */

    int i;

    for (i = 0; string[i] != '\0'; i++);

    return i;
}