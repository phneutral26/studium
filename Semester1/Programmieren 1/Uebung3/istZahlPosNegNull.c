#include<stdio.h>

int main(void)
{
    int num1;

    printf("Geben sie die erste Zahl an: ");
    scanf("%d", &num1);
    if (num1 > 0) {
        printf("Die Zahl ist positiv.\n");
    }
    else if (num1 < 0)
    {
        printf("Die Zahl ist negativ.\n");
    }
    else {
        printf("Die Zahl ist null.\n");
    }
    return 0;
}
