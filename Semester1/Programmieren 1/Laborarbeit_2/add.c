#include <stdio.h>

int succ(int x) { return ++x; }

int neg(int x) { return -x; }

int add(int a, int b) {
  if (b == 0) {
    return a;
  } else if (b > 0) {
    return add(succ(a), neg(succ(neg(b))));
  } else {
    return add(neg(succ(neg(a))), succ(b));
  }
}

int main() {
  int a = 999, b = -1113;
  printf("Ergebnis von(%d + %d): %d\n", a, b, add(a, b));
  return 0;
}
