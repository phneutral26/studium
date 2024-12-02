#include <stdio.h>
#include <string.h>

void reverse_string(char *str) {
  char *end = str + strlen(str) - 1; 
  char temp;
  while (str < end) {
    temp = *str;
    *str = *end;
    *end = temp;
    str++;
    end--;
  }
}

int main(int argc, char *argv[]) {
  char str[] = "";

  printf("Geben Sie einen String ein: ");
  scanf("%[^\n]s", str);

  printf("Eingabe: %s\n", str);
  reverse_string(str);
  printf("Umgekehrte Ausgabe: %s\n", str);

  return 0;
}