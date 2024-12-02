#include<stdio.h>

int main(void){
    float tempCelsius;
    
    printf("Geben sie die Temperatur in Celsius an: ");
    scanf("%f", &tempCelsius);

    float tempFahrenheit = (tempCelsius*9)/5+32;

    printf("Die Temperatur in Fahrenheit beträgt: %f\n", tempFahrenheit);
    return 0;
}