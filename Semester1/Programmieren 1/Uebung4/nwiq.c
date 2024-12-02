#include <stdio.h>

void draw_house(int n) {
    // Dach
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Haus
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - 1; j++) {
            printf(" ");
        }
        printf("******\n");
    }
}

int main() {
    int n;

    printf("Bitte geben Sie die Größe des Hauses ein (n > 0): ");
    scanf("%d", &n);

    // Zeichne das Haus des Nikolaus
    draw_house(n);

    // Zeichne das Haus des Weihnachtsmannes direkt darunter
    draw_house(n);

    return 0;
}