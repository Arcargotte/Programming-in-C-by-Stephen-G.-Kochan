/* 
 * Type in and run the 15 programs presented in this chapter. 
 * Compare the output produced by each program with the output presented after 
 * each program in the text
 */

#include <stdio.h>

// // Program 11.1

// int main (void)
// {
//     int count = 10, x;
//     int *int_pointer;

//     int_pointer = &count;
//     x = *int_pointer;
//     printf ("count = %i, x = %i", count, x);

//     return 0;
// }

/* OBSERVATIONS
 * a) if you assign a value of the same type to such a pointer, it returns an error
 * b) if you don't use the indirection operator when assigning a pointer to a variable, it
 *    returns the address of the variable that pointer is pointing to
 * c) you can use the address operator '&' to get the address of any variable
 */

// Program 11.2

// int main (void)
// {
//     char c = 'Q';
//     char *char_pointer = &c;

//     printf ("%c %c\n", c, *char_pointer);

//     c = '/';

//     printf ("%c %c\n", c, *char_pointer);

//     *char_pointer = '(';

//     printf ("%c %c\n", c, *char_pointer);

//     return 0;
// }

// Program 11.3

// int main (void)
// {
//     int i1, i2;
//     int *p1, *p2;

//     i1 = 5;
//     p1 = &i1;
//     i2 = *p1 / 2 + 10;
//     p2 = p1;

//     printf ("i1 = %i, i2 = %i, *p1 = %i, *p2 = %i\n", i1, i2, *p1, *p2);

//     return 0;
// }

// Program 11.4

// int main (void)
// {
//     struct date
//     {
//         int month;
//         int day;
//         int year;
//     };

//     struct date today, *datePtr;

//     datePtr = &today;
//     datePtr->month = 9;
//     datePtr->day = 25;
//     datePtr->year = 2004;

//     printf ("Today's date is %i/%i/%.2i.\n", datePtr->month, datePtr->day, datePtr->year % 100);

//     return 0;
// }

// Program 11.5

// #include <stdio.h>
// int main (void)
// {
//     struct intPtrs
//     {
//         int *p1;
//         int *p2;
//     };

//     struct intPtrs pointers;
//     int i1 = 100, i2;

//     pointers.p1 = &i1;
//     pointers.p2 = &i2;
//     *pointers.p2 = -97; // <- Since the structure member operator '.' has higher precedence

//     printf ("i1 = %i, *pointers.p1 = %i\n", i1, *pointers.p1);
//     printf ("i2 = %i, *pointers.p2 = %i\n", i2, *pointers.p2);

//     return 0;
// }

// Program 11.6

// int main (void)
// {
//     struct entry
//     {
//         int value;
//         struct entry *next;
//     };

//     struct entry n1, n2, n3;
//     int i;

//     n1.value = 100;
//     n2.value = 200;
//     n3.value = 300;
//     n1.next = &n2; // <- Assigning the address of n2 to the pointer next of n1
//     n2.next = &n3; // <- Assigning the address of n3 to the pointer next of n2
//     i = n1.next->value;

//     printf ("%i ", i);
//     printf ("%i\n", n2.next->value);

//     return 0;
// }

// Program 11.7

// int main (void)
// {
//     struct entry
//     {
//         int value;
//         struct entry *next;
//     };

//     struct entry n1, n2, n3;
//     struct entry *list_pointer = &n1;

//     n1.value = 100;
//     n1.next = &n2;
//     n2.value = 200;
//     n2.next = &n3;
//     n3.value = 300;
//     n3.next = (struct entry *) 0; // Mark list end with null pointer
    
//     while ( list_pointer != (struct entry *) 0 ) {
//         printf ("%i\n", list_pointer->value);
//         list_pointer = list_pointer->next;
//     }

//     return 0;
// }

// Program 11.8

// void test (int *int_pointer)
// {
//     *int_pointer = 100;
// }

// int main (void)
// {
//     void test (int *int_pointer);
//     int i = 50, *p = &i;

//     printf ("Before the call to test i = %i\n", i);

//     test (p); // <- You are passing the address as an argument to the function

//     printf ("After the call to test i = %i\n", i);

//     return 0;
// }

// Program 11.9

// void exchange (int * const pint1, int * const pint2)
// {
//     int temp;

//     temp = *pint1;
//     *pint1 = *pint2;
//     *pint2 = temp;
// }

// int main (void)
// {
//     void exchange (int * const pint1, int * const pint2); // <- Address is constant, value is not
//     int i1 = -5, i2 = 66, *p1 = &i1, *p2 = &i2;

//     printf ("i1 = %i, i2 = %i\n", i1, i2);

//     exchange (p1, p2);

//     printf ("i1 = %i, i2 = %i\n", i1, i2);

//     exchange (&i1, &i2); // <- Valid call to a function since you are passing addresses

//     printf ("i1 = %i, i2 = %i\n", i1, i2);

//     return 0;
// }

/*
 * As functions copies the values of the arguments passed into them, pointers allow setting
 * and assigning new values. The address that pointers point to cannot be changed in the function 
 * 
 */

// Program 11.10

// struct entry
// {
//     int value;
//     struct entry *next;
// };

// struct entry *findEntry (struct entry *listPtr, int match)
// {
//     while ( listPtr != (struct entry *) 0 )
//         if ( listPtr->value == match )
//             return (listPtr);
//         else
//             listPtr = listPtr->next;

//     return (struct entry *) 0;
// }

// int main (void)
// {
//     struct entry *findEntry (struct entry *listPtr, int match);
//     struct entry n1, n2, n3;
//     struct entry *listPtr, *listStart = &n1;
//     int search;

//     n1.value = 100;
//     n1.next = &n2;
//     n2.value = 200;
//     n2.next = &n3;
//     n3.value = 300;
//     n3.next = 0;

//     printf ("Enter value to locate: ");
//     scanf ("%i", &search);

//     listPtr = findEntry (listStart, search);

//     if ( listPtr != (struct entry *) 0 )
//         printf ("Found %i.\n", listPtr->value);
//     else
//         printf ("Not found.\n");

//     return 0;
// }

// Program 11.11

// int arraySum (int array[], const int n)
// {
//     int sum = 0, *ptr;
//     int * const arrayEnd = array + n;

//     for ( ptr = array; ptr < arrayEnd; ++ptr )
//         sum += *ptr;

//     return sum;
// }

// int main (void)
// {
//     int arraySum (int array[], const int n);
//     int values[10] = { 3, 7, -9, 3, 6, -1, 7, 9, 1, -5 };

//     printf ("The sum is %i\n", arraySum (values, 10));

//     return 0;
// }

/* 
 * the function arraySum uses the formula *(arrayPtr + i) to point to the last element of the array
 * so that the while loop inside goes through each element until it reaches the end summing all of 
 * them, and storaging to the integer variable sum
 */

// Program 11.12

// int arraySum (int *array, const int n)
// {
//     int sum = 0;
//     int * const arrayEnd = array + n;

//     for ( ; array < arrayEnd; ++array )
//         sum += *array;

//     return sum;
// }

// int main (void)
// {
//     int arraySum (int *array, const int n);
//     int values[10] = { 3, 7, -9, 3, 6, -1, 7, 9, 1, -5 };

//     printf ("The sum is %i\n", arraySum (values, 10));

//     return 0;
// }

/*
 * As valuePtr, if it's a pointer to integer and the array it's pointing to is an array of integers,
 * the expression *(valuePtr + i) refers to the ith element in the array. Because of this, arrays
 * and pointers are intimately related, and since what you pass to a function that takes an array
 * as its argument is actually a pointer to such array  
 */

// Program 11.13

// void copyString (char *to, char *from)
// {
//     for ( ; *from != '\0'; ++from, ++to )
//         *to = *from;

//     *to = '\0';
// }

// int main (void)
// {
//     void copyString (char *to, char *from);
//     char string1[] = "A string to be copied.";
//     char string2[50];
//     char string3[50] = {"Hello", "world"}; // <- You cannot do this

//     copyString (string2, string1);

//     printf ("%s\n", string2);

//     copyString (string2, "So is this.");

//     printf ("%s\n", string2);

//     return 0;
// }

// Program 11.14

// void copyString (char *to, char *from)
// {
//     while ( *from )
//         *to++ = *from++;
//     *to = '\0';
// }

// int main (void)
// {
//     void copyString (char *to, char *from);
//     char string1[] = "A string to be copied.";
//     char string2[50];

//     copyString (string2, string1);

//     printf ("%s\n", string2);

//     copyString (string2, "So is this.");

//     printf ("%s\n", string2);


//     return 0;
// }

// Program 11.15

// int stringLength (const char *string)
// {
//     const char *cptr = string;

//     while ( *cptr )
//         ++cptr;

//     return cptr - string; // <- The value type resulting from substracting two pointers is ptrdiff_t
// }

// int main (void)
// {
//     int stringLength (const char *string);

//     printf ("%i ", stringLength ("stringLength test"));
//     printf ("%i ", stringLength (""));
//     printf ("%i\n", stringLength ("complete"));

//     return 0;
// }