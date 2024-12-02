#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void reverse_string(char *str)
{
    /* skip null */
    if (str == 0)
    {
        return;
    }

    /* skip empty string */
    if (*str == 0)
    {
        return;
    }

    /* get range */
    char *start = str;
    char *end = start + strlen(str) - 1; /* -1 for \0 */
    char temp;

    /* reverse */
    while (end > start)
    {
        /* swap */
        temp = *start;
        *start = *end;
        *end = temp;

        /* move */
        ++start;
        --end;
    }
}


bool isPalindrome(char* p);

int main (int argc, char *argv[]) {
    char str[] = "";
    printf("Geben Sie einen String ein: ");
    scanf("%[^\n]s", str);

    if (isPalindrome(str)) {
        printf("Der eingegebene String ist ein Palindrom.\n");
    } else {
        printf("Der eingegebene String ist kein Palindrom.\n");
    }


    return 0;
}

bool isPalindrome(char* p) {
  char str[] = "";
  strcpy(p, str);
  // reverse string
  reverse_string(p);

  // compare with original string
  return strcmp(p, str) == 0;
}