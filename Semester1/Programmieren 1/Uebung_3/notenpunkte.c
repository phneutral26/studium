#include <stdio.h>

int main() {
    float maxPoints, achievedPoints;
    
    printf("Gib Maximale Punktzahl an: ");
    scanf("%f", &maxPoints);
    printf("Gib erreichte Punktzahl an: ");
    scanf("%f", &achievedPoints);
    
    float percentage = (achievedPoints / maxPoints) * 100;
    float grade;

    if (percentage < 50) {
        grade = 5.0;
    } else if (percentage < 55) {
        grade = 4.0;
    } else if (percentage < 60) {
        grade = 3.7;
    } else if (percentage < 65) {
        grade = 3.3;
    } else if (percentage < 70) {
        grade = 3.0;
    } else if (percentage < 75) {
        grade = 2.7;
    } else if (percentage < 80) {
        grade = 2.3;
    } else if (percentage < 85) {
        grade = 2.0;
    } else if (percentage < 90) {
        grade = 1.7;
        
    } else if (percentage < 95) {
        grade = 1.3;
    } else {
        grade = 1.0;
    }
    
    printf("Die Note ist: %f\n", grade);
    
    printf("\nLegende:\n");
    printf("%% Bereich  Note\n");
    printf("< 50%%     5.0\n");
    printf("50%%-54%%  4.0\n");
    printf("55%%-59%%  3.7\n");
    printf("60%%-64%%  3.3\n");
    printf("65%%-69%%  3.0\n");
    printf("70%%-74%%  2.7\n");
    printf("75%%-79%%  2.3\n");
    printf("80%%-84%%  2.0\n");
    printf("85%%-89%%  1.7\n");
    printf("90%%-94%%  1.3\n");
    printf(">= 95%%   1.0\n");

    return 0;
}
