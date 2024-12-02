#include <stdbool.h>
#include <stdio.h>

unsigned long long binom(unsigned int n, unsigned int k) {
  if (k > n) {
    return 0;
  }
  unsigned long long ergebnis = 1;
  // binomialkoeffizienten symmetrie
  if (k > n - k) {
    k = n - k;
  }

  for (int i = 1; i <= k; i++) {
    ergebnis = ergebnis * (n - i + 1) / i;
  }

  return ergebnis;
}

int main() {
  unsigned int n = 67, k = 50;
  printf("Binomialkoeffizient von %u über %u ist: %llu\n", n, k, binom(n, k));
  return 0;
}

// größtmöglichstes _n_ für den Algorithmus: 67, da 2^64-1 Speicherlimit bei
// unsigned long long
