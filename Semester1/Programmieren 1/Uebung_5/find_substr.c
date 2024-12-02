#include <stdio.h>
#include <string.h>

int find_substring(char *str, char *substr) {
  int len_str = strlen(str);
  int len_substr = strlen(substr);

  for (int i = 0; i <= len_str - len_substr; i++) {
    int j;
    for (j = 0; j < len_substr; j++) {
      if (str[i + j] != substr[j]) {  // Vergleich nicht erfolgreich
        break;
      }
    }
    if (j == len_substr) {  // Vergleich erfolgreich
      printf("Startadresse des Substrings: %p\n", (void *)&str[i]);
      return i;  // Index des ersten Zeichens des gefundenen Substrings
    }
  }
  return -1;  // Substring nicht gefunden
}



int main() {
  char str[] = "Hallo Herr Prof. Goldau!";
  char substr[] = "Prof";


  printf("Hauptzeichenkette: %s\n", str);
  printf("Substring: %s\n", substr);

  int result = find_substring(str, substr);
  if (result != -1) {
    printf("Substring gefunden an Index %d.\n", result);
  } else {
    printf("Substring nicht gefunden.\n");
  }

  return 0;
}
