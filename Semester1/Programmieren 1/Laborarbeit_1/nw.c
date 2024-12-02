#include <stdio.h>

void zeichneDach(int n)
{
    for (int i = 0; i < n / 2 + n%2; i++)
    {
        for (int k = 0; k < 2; k++)
        {
            for (int j = 0; j < n * 2; j++)
            {
                if (j == n / 2 + i || // rechte seite
                    j == n / 2 - i - (1 - n % 2) || // linke seite
                    j == (n / 2 + i) + n - 1 || // rechte seite +n
                    j == (n / 2 - i - (1 - n % 2)) + n - 1 // linke seite +n
                    )
                {
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");

            //fix für ungerade seitenzahlen
            if(1==n%2 && i == n/2)
            {
                return;
            }
        }
    }
}
void zeichneKoerper(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * 2 - 1; j++)
        {
            // Kante links|| Kante rechts || Kante oben|| Kante unten|| Diagonale|| Diagonale      || 2. Kante rechts || 2. Diagonale       || 2. Diagonale
            if (j == 0    || j == n - 1   || i == 0    || i == n - 1 || i == j   || i == n - j - 1 || j == n * 2 - 2  || i == n * 2 - j - 2 || j == i + n - 1)
            {
                // printf("%d,%d ", i, j);
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}
int main()
{
    int n;
    printf("Geben sie die Seitenlänge an: ");
    scanf("%d", &n);

    if (n < 5)
    {
        printf("Bitte gib eine Zahl größer oder gleich 5 ein.\n");
        return 1;
    }

    zeichneDach(n);
    zeichneKoerper(n);

    return 0;
}
