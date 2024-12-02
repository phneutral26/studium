#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void siebDesErastosthenes(int n) {
    if (n < 2) {
	printf("Keine Primzahlen im Bereich.\n");
	return;
    }

    // Array zur Speicherung der Primzahlstatus
    bool *isPrime = (bool *)malloc((n + 1) * sizeof(bool));
    memset(isPrime, true, (n + 1) * sizeof(bool));

    for (int p = 2; p * p <= n; p++) {
	// Wenn p eine Primzahl ist, markiere Vielfache
	if (isPrime[p]) {
	    for (int j = p * p; j <= n; j += p) {
		isPrime[j] = false;  // Markiere als nicht-prim
	    }
	}
    }

    printf("Primzahlen bis %d:\n", n);
    for (int i = 2; i <= n; i++) {
	if (isPrime[i]) {
	    printf("%d ", i);
	}
    }
    printf("\n");

    free(isPrime);
}

int main() {
  int n;
  printf("Geben Sie die obere Grenze (n) ein: ");
  scanf("%d", &n);
  siebDesErastosthenes(n);
  return 0;
}
