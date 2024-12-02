#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  printf("Anzahl der Argumente: %d\n", argc);  // Anzahl der Argumente ausgeben mit _argc_
  
  for (int i = 0; i < argc; i++) {
    printf("Argument %d: %s (Länge: %lu)\n", i, argv[i], strlen(argv[i]));
  }

  return 0;
}
