#include <stdio.h>

int main () {

    int temp;

    printf("Geben sie die Temperatur an: ");
    scanf("%d", &temp);


    if (temp < 0)
    {
        printf("Es ist sehr kalt\n");
    }
    else if (0 <= temp && temp <= 10) {
        printf("Es ist kalt\n");
    }
    else if (11 <= temp && temp <= 20)
    {
        printf("Es ist kühl\n");
    }
    else if (temp > 20 )
    {
        printf("Es is warm\n");
    }

    return 0;
}