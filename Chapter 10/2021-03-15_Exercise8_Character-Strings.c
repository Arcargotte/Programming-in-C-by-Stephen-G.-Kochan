/* Using the findString, removeString, and insertString functions 
 * from preceding exercises, write a function called replaceString
 * that takes three character string arguments as follows
 * 
 *             replaceString (source, s1, s2);
 * 
 * and that replaces s1 inside source with the character string s2.
 * The function should call the findString function to locate s1 
 * inside source, then call the removeString to remove s1 from source, 
 * and finally call the insertString function to insert s2 into source 
 * at the proper location. So, the function call
 * 
 *             replaceString (text, "1", "one");
 * 
 * replaces the first occurrence of the character string "1" inside 
 * the character string text, if it exists, with the string "one". 
 * Similarly, the function call
 * 
 *             replaceString (text, "*", "");
 * 
 * has the effect of removing the first asterisk inside 
 * the text array because the replacement string is the null string.
 */

#include <stdio.h>

int main (void)
{
    int stringLength (const char string[]);
    int findString (char source[], char subString[]);
    void removeString (char text[], int position, int n);
    void insertString (char text[], char string[], int position);
    void replaceString (char source[], char s1[], char s2[]);

    char source[] = "He threw three free throws three";

    replaceString(source, "three", "3");

    printf("%s", source);

    return 0;
}

int stringLength (const char text[])
{
    /* Takes an array of characters and returns its length */

    int i; 

    for (i = 0; text[i] != '\0'; i++);

    return i;
}

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

void removeString (char text[], int position, int n)
{
    /* Takes an array of characters, a subscript and the number of elements to be erased from that point.
     * It returns the same array without the elements from position to position + n 
     * 
     * It only works when printing the string, but the array of character still contains some characters
     * that are not reset during execution
     */

    int stringLength (const char text[]);
    int length = stringLength(text);

    for (int i = position + n; i <= length; i++)
    {
        text[position++] = text[i];
    }
}

void insertString (char text[], char string[], int position)
{
    int stringLength (const char string[]);
    int len = stringLength (text);
    int insertionLen = stringLength (string);
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

void replaceString (char source[], char s1[], char s2[])
{
    /*
     * Takes an array of characters source, a subarray s1 and a string s2 which is replacing s1 in source.
     * It replaces the first occurrence of s1 in source for s2 
     */

    int stringLength (const char text[]);
    int findString (char source[], char subString[]);
    void removeString (char text[], int position, int n);

    int occurrence = findString (source, s1);
    int s1Length = stringLength (s1);

    removeString (source, occurrence, s1Length);
    insertString(source, s2, occurrence);
}