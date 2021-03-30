/**
 * Given the following declarations
 * 
 *              char *message = "Programming in C is fun\n";
 *              char message2[] = "You said it\n";
 *              char *format = "x = %i\n";
 *              int x = 100;
 * 
 * determine whether each printf call from the following sets is valid and produces
 * the same output as other calls from the set.
 */

#include <stdio.h>

int main (void)
{
    char *message = "Programming in C is fun\n";
    char message2[] = "You said it\n";
    char *format = "x = %i\n";
    int x = 100;

    /*** set 1 ***/

    // printf ("Programming in C is fun\n");
    // printf ("%s", "Programming in C is fun\n");
    // printf ("%s", message);
    // printf (message); 

    // /*** set 2 ***/

    // printf ("You said it\n"); // -> prints normally
    // printf ("%s", message2); // -> prints normally
    // printf (message2); // -> prints normally
    // printf ("%s", &message2[0]); // -> prints normally as &message2[0] <=> message2

    // /*** set 3 ***/

    // printf ("said it\n"); // -> prints normally
    // printf (message2 + 4); // -> prints said it
    // printf ("%s", message2 + 4); // -> prints said it
    // printf ("%s", &message2[4]); // -> prints said it

    // /*** set 4 ***/

    printf ("x = %i\n", x); // -> prints normally
    printf (format, x); // -> prints normally

    return 0;
}
