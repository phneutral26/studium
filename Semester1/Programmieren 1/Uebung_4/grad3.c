#include <stdio.h>

void notenLegende(int max_punkte)
{
    printf("Geben Sie die maximale Punktzahl ein: %d\n", max_punkte);
    printf("Legende (Prozente für jede Note):\n");

    for (int prozent = 95, stufe = 0; prozent >= 45; prozent -= 5, stufe++)
    {
        double note = 1.0 + (stufe / 3.0);
        int untere_grenze = (prozent * max_punkte + 99) / 100;         // Aufrundung durch +99
        int obere_grenze = ((prozent + 5) * max_punkte + 99) / 100 - 1;

        if (prozent == 95)
        {
            obere_grenze = max_punkte;
            printf("Note %.1f: %d%% <= x <= %d%% (%d-%d Punkte)\n", note, prozent, prozent + 5, untere_grenze, obere_grenze);
            continue;
        }
        if (prozent < 50)
        {
            printf("Note 5.0: x < 50%%\n");
        }
        else
        {
            printf("Note %.1f: %d%% <= x < %d%% (%d-%d Punkte)\n", note, prozent, prozent + 5, untere_grenze, obere_grenze);
        }
    }
}

int main()
{
    int max_punkte;
    printf("Bitte geben Sie die maximale Punktzahl ein: ");
    scanf("%d", &max_punkte);

    notenLegende(max_punkte);

    return 0;
}
