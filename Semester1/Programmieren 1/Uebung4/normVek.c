#include <math.h>
#include <stdio.h>

void normiere_vektor(double *vektor, int dim)
{
    double norm = 0.0;
    for (int i = 0; i < dim; i++)
    {
        norm += vektor[i] * vektor[i];
    }
    norm = sqrt(norm);
    for (int i = 0; i < dim; i++)
    {
        vektor[i] /= norm;
    }
}

int main()
{
    double vektor[3] = {3.0, 4.0, 0.0};
    int dim = 3;

    normiere_vektor(vektor, dim);

    // print the normalized vector
    for (int i = 0; i < dim; i++)
    {
        printf("%.2f ", vektor[i]);
    }
    printf("\n");

    return 0;
}