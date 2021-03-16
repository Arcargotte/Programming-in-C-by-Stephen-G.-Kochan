/* Write a function called removeString to remove a specified number of characters
 * from a character string.The function should take three arguments: the source
 * string, the starting index number in the source string, and the number of characters to remove. 
 * So, if the character array text contains the string "the wrong son", the call
 *
 *                               removeString(text, 4, 6);
 *
 * has the effect of removing the characters “wrong “ (the word “wrong” plus the
 * space that follows) from the array text.The resulting string inside text is then
 * "the son".
*/

#include <stdio.h>

int main (void)
{
    void removeString (char text[], int position, int n);
    int stringLength (const char text[]);
    char str1[] = "the wrong son";

    removeString(str1, 4, 6);

    printf("%s", str1);

    return 0;
}

int stringLength (const char text[])
{
    /* Takes an array of characters and returns its length */

    int i; 

    for (i = 0; text[i] != '\0'; i++);

    return i;
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