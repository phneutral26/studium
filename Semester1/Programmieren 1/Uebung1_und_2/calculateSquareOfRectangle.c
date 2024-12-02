#include<stdio.h>

int main(void){
    float recLength;
    float recHeight;
    
    printf("Geben sie die Breite des Rechtecks an: ");
    scanf("%f", &recLength);

    printf("Geben sie die Höhe des Rechtecks an: ");
    scanf("%f", &recHeight);
    
    float recSquare = recLength * recLength;
    printf("Die Fläche des Rechtecks beträgt: %f\n", recSquare);

    return 0;
}