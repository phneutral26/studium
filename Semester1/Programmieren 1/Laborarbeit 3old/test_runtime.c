#include <stdio.h>
#include <time.h>

#define NUM_TOWERS 3
#define MAX_DISCS 20
#define TOWER_SIZE (MAX_DISCS + 1)

#define NUM_TESTS 5 // Number of repetitions for averaging

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
    FILE *file = fopen("hanoi_runtimes_avg.csv", "w");
    if (file == NULL) {
        printf("Error: Unable to create CSV file.\n");
        return 1;
    }

    fprintf(file, "Max_Discs,Average_Runtime_Seconds\n");

    for (int discs = 3; discs <= MAX_DISCS; discs++) {
        double total_runtime = 0.0;

        for (int test = 0; test < NUM_TESTS; test++) {
            clock_t start = clock();

            towers_t state = {0};
            for (int i = 0; i < discs; i++) {
                state[0][i] = i + 1;
            }

            hanoi(discs, state, 0, 2);

            clock_t end = clock();
            total_runtime += (double)(end - start) / CLOCKS_PER_SEC;
        }

        double average_runtime = total_runtime / NUM_TESTS;
        fprintf(file, "%d,%f\n", discs, average_runtime);
        printf("Max_Discs: %d, Average Runtime: %f seconds\n", discs, average_runtime);
    }

    fclose(file);
    printf("Average runtimes have been saved to hanoi_runtimes_avg.csv.\n");
    return 0;
}