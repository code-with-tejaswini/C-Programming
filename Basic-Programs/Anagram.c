#include <stdio.h>
#include <string.h>
#include <ctype.h>

int areAnagrams(const char *str1, const char *str2);

int main()
{
    char str1[100], str2[100];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    if (areAnagrams(str1, str2))
        printf("%s and %s are anagrams.\n", str1, str2);
    else
        printf("%s and %s are not anagrams.\n", str1, str2);

    return 0;
}

int areAnagrams(const char *str1, const char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2)
        return 0; // If the lengths are different, they cannot be anagrams

    // Create character frequency arrays
    int count1[26] = {0}; // Assuming lowercase alphabets

    // Count the frequency of characters in str1
    for (int i = 0; i < len1; i++)
    {
        count1[tolower(str1[i]) - 'a']++;
        count1[tolower(str2[i]) - 'a']--;
    }

    // If the strings are anagrams, all counts should be zero
    for (int i = 0; i < 26; i++)
    {
        if (count1[i] != 0)
            return 0; // If any count is non-zero, they are not anagrams
    }

    return 1; // If all counts are zero, they are anagrams
}
