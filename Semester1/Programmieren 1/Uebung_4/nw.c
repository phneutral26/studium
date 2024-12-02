#include <stdio.h>

void print_roof(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n + 3; j++) {
            if (j == n - i || j == n + 1 + i) {
                printf("*");
            } else if (j > n - i && j < n + 1 + i) {
                printf(" ");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void print_middle_wall(int n) {
    for (int j = 0; j < 2 * n + 3; j++) {
        printf("*");
    }
    printf("\n");
}

void print_walls(int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("*");
        for (int j = 0; j < n - 1; j++) {
            printf(" ");
        }
        printf("*");
        printf("*");
        for (int j = 0; j < n - 1; j++) {
            printf(" ");
        }
        printf("*");
        printf("\n");
    }
}

int main() {
    int n;

    // Read the size of the house from the user
    printf("Enter the size of the house (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. n should be greater than 0.\n");
        return 1;
    }

    // Print the roofs of the two houses
    print_roof(n);

    // Print the middle wall
    print_middle_wall(n);

    // Print the walls and floor
    print_walls(n);

    // Print the floor
    print_middle_wall(n);

    return 0;
}
