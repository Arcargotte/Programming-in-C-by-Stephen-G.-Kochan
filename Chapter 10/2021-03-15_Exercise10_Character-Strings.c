/*
 * Write a function called dictionarySort that sorts a dictionary, as defined in
 * Programs 10.9 and 10.10, into alphabetical order.
 */

// Dictionary lookup program

#include <stdio.h>

struct entry
{
char word[15];
char definition[50];
};

// Function to compare two character strings
int compareStrings (const char s1[], const char s2[])
{
    int i = 0, answer;

    while ( s1[i] == s2[i] && s1[i] != '\0'&& s2[i] != '\0' )
        ++i;

    if ( s1[i] < s2[i] )
        answer = -1; /* s1 < s2 */
    else if ( s1[i] == s2[i] )
        answer = 0; /* s1 == s2 */
    else
        answer = 1; /* s1 > s2 */

    return answer;
}

// Function to look up a word inside a dictionary
int lookup (const struct entry dictionary[], const char search[], const int entries)
{
    int low = 0;
    int high = entries - 1;
    int mid, result;
    int compareStrings (const char s1[], const char s2[]);

    while ( low <= high )
    {
        mid = (low + high) / 2;
        result = compareStrings (dictionary[mid].word, search);

        if ( result == -1 )
            low = mid + 1;
        else if ( result == 1 )
            high = mid - 1;
        else
            return mid; /* found it */
    }

    return -1; /* not found */
}

void dictionarySort (struct entry dictionary[], int entries)
{
    int i, j;
    struct entry temp;

    for (i = 0; i < entries; i++)
    {
        for (j = i + 1; j < entries; j++)
        {
            if (compareStrings(dictionary[i].word, dictionary[j].word) == 1)
            {
                temp = dictionary[i];
                dictionary[i] = dictionary[j];
                dictionary[j] = temp;
            }
        }
    }
}

int main (void)
{
	struct entry dictionary[100] = 
		{ { "aardvark", "a burrowing African mammal"             },
		  { "affix",    "to append; attach"                      },
		  { "ahoy",     "a nautical call of greeting"            },
		  { "abyss",    "a bottomless pit"                       },
		  { "ajar",     "partially opened"                       },
		  { "acumen",   "mentally sharp; keen"                   },
		  { "aerie",    "a high nest"                            },
		  { "addle",    "to become confused"                     },
		  { "agar",     "a jelly made from seaweed"              },
		  { "aigrette", "an ornamental cluster of feathers"      } };
    
    void dictionarySort (struct entry dictionary[], int entries);

    dictionarySort(dictionary, 10);

    int i = 0;
    for (; i < 10; i++);
        printf("%s %s\n", dictionary[i].word, dictionary[i].definition);

    return 0;
}