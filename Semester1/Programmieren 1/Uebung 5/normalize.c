#include <math.h>
#include <stdio.h>


void normalize(double *x, double *y) {
  double norm = sqrt((*x) * (*x) + (*y) * (*y));  // Norm des Vektors berechnen

  if (norm != 0) {
    *x = *x / norm;
    *y = *y / norm;
  }
}

int main() {
  double x, y;

  printf("Geben Sie den X-Wert ein: ");
  scanf("%lf", &x);
  printf("Geben Sie den Y-Wert ein: ");
  scanf("%lf", &y);

  draw_vector(x, y);

  normalize(&x, &y);
  printf("x = %f, y = %f\n", x, y);
  printf("Länge des neuen Vektors (sollte 1.0 sein) : %f\n", sqrt(x*x + y*y));
  return 0;
}