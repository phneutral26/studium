#include<stdio.h>

int main(void){
    int num1;
    int num2;

    printf("Geben sie die erste Zahl an: ");
    scanf("%d", &num1);

    printf("Geben sie die zweite Zahl an: ");
    scanf("%d", &num2);

    int max = num1 > num2 ? num1 : num2;

    

    printf("Max: %d\n", max);

    return 0;
}
