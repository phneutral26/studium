#include <stdio.h>
#include <time.h>

#define NUM_TOWERS 3
#define MAX_DISCS 28 // Anzahl der Scheiben für die noch der Durchschnitt berechnet wird
#define TOWER_SIZE (MAX_DISCS + 1)
#define NUM_TESTS 5 // Anzahl der Wiederholung um den Durchschnitt zu berechnen

typedef int towers_t[NUM_TOWERS][TOWER_SIZE];


/**
 * Das Programm wiederholt die Laufzeitanalyse NUM_TESTS-mal durch und speichert die jeweiligen Daten in einer CSV-Datei: hanoi_runtimes_avg.csv
 * Die Ausführungszeiten scheinen sich für jeden Durchlauf zu verdoppeln: O(2^n)
*/

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
    hanoi(n - 1, state, helper, to);
}

int main() {
    FILE *file = fopen("hanoi_runtimes_avg.csv", "w");
    if (file == NULL) {
        printf("Konnte keine CSV Datei erstellen.\n");
        return 1;
    }

    fprintf(file, "MAX_DISCS,Durchschnittliche_Laufzeit\n");

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
        printf("MAX_DISCS: %d, Durchschnittliche Laufzeit: %f seconds\n", discs, average_runtime);
    }

    fclose(file);
    printf("Durchschnittliche Laufzeiten wurden in hanoi_runtimes_avg.csv gespeichert.\n");
    return 0;
}
