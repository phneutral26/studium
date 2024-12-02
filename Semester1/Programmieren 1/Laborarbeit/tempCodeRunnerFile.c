if (obere_grenze < untere_grenze) // Für nicht besetzte Noten fragezeichen ausgeben
            {
                printf("Note %.1f: %d%% <= x < %d%% (?-? Punkte)\n", note, prozent, prozent + 5);
                continue;
            }