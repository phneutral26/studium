#include<stdio.h>

int main(void){
    int num1;
    int num2;

    printf("Geben sie die erste Zahl an: ");
    scanf("%d", &num1);

    printf("Geben sie die zweite Zahl an: ");
    scanf("%d", &num2);

    float avg = (float)(num1+num2)/2;

    printf("Durchschnitt: %.4f\n", avg);

    return 0;
}

