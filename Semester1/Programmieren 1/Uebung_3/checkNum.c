#include <stdio.h>

int main () {
    int num;
    printf("Gib Zahl an: ");
    scanf("%d", &num);
    if (num==0)
    {
        printf("Die Zahl ist null.\n");
    }
    if (num % 2 == 0 && num > 0)
    {
        printf("Die Zahl ist positiv und gerade.\n");
    }
    else if (num % 2 != 0 && num > 0)
    {
        printf("Die Zahl ist positiv und ungerade.\n");
    }
    else if (num % 2 == 0 && num < 0)
    {
        printf("Die Zahl ist negativ und gerade.\n");
    }
    else if (num % 2 != 0 && num < 0)
    {
        printf("Die Zahl ist negativ und ungerade.\n");
    }
    return 0;
}