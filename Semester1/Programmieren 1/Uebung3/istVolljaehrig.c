#include <stdio.h>
#include <stdbool.h>


int main () {
    int alter;
    bool hatFuehrerschein;

    printf("Gib Alter an: ");
    scanf("%d", &alter);

    int temp;
    printf("Hat Führerschein? ");
    scanf("%d", &temp);
    hatFuehrerschein = temp;

    if (alter >= 18 && hatFuehrerschein)
    {
        printf("Erlaubnis zum Autofahren.\n");
    }
    else
    {
        printf("Keine Erlaubnis zum Autofahren.\n");
    }
    return 0;
}