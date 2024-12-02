#include <stdio.h>

int skalarprodukt(int x1[], int x2[], int length)
{
    int skalarprodukt = 0;

    for (int i = 0; i < length; i++)
    {
        skalarprodukt += x1[i] * x2[i];
    }

    return skalarprodukt;
}

int main()
{
    int x1[] = {5};
    int x2[] = {5};

    if (sizeof(x1) != sizeof(x2))
    {
        printf("Nicht gleich-lange Arrays!\n");
        return -1;
    }

    int length = sizeof(x1) / sizeof(x1[0]);

    int ergebnis = skalarprodukt(x1, x2, length);
    printf("%d\n", ergebnis);
    return 0;
}
