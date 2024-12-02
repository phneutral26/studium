#include <stdio.h>
#define NUM_TOWERS 3
#define MAX_DISCS 3
#define TOWER_SIZE (MAX_DISCS + 1)

typedef int towers_t[NUM_TOWERS][TOWER_SIZE];

void printTowers(towers_t state) {
  printf("Zustand der Tuerme:\n");
  for (int i = 0; i < MAX_DISCS; i++) {
    for (int j = 0; j < NUM_TOWERS; j++) {
      if (state[j][i] == 0) {
        printf("  | ");
      } else {
        printf("  %d ", state[j][i]);
      }
    }
    printf("\n");
  }
  printf("  =   =   =  \n  A   B   C  \n\n");
}

void bewegeScheibe(towers_t state, int from, int to) {
  int übergabeScheibe = 0;
  for (int i = 0; i < MAX_DISCS; i++) {
    if (state[from][i] != 0) {
      übergabeScheibe = state[from][i];
      state[from][i] = 0;
      break;
    }
  }
  for (int i = MAX_DISCS - 1; i >= 0; i--) {
    if (state[to][i] == 0) {
      state[to][i] = übergabeScheibe;
      break;
    }
  }
}

void hanoi(int n, towers_t state, int from, int to) {
  if (n == 0) {
    return;
  }

  int helper = 3 - from - to;

  hanoi(n - 1, state, from, helper);
  bewegeScheibe(state, from, to);
  printTowers(state);
  hanoi(n - 1, state, helper, to);
}

int main() {
  towers_t state = {0};
  for (int i = 0; i < MAX_DISCS; i++) {
    state[0][i] = i + 1;
  }

  printf("Anfangszustand:\n");
  printTowers(state);

  hanoi(MAX_DISCS, state, 0, 2);
  return 0;
}
