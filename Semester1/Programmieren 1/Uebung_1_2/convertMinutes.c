#include<stdio.h>

int main(void){
    int minutes;

    printf("Geben sie die Anzahl an Minuten ein: ");
    scanf("%d", &minutes);

    int hours = minutes/60;
    minutes = minutes % 60;

    printf("%d Stunden : %d Minuten\n", hours, minutes);

    return 0;
}