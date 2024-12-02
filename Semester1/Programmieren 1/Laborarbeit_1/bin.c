#include <stdio.h>

long bin_search_rec(int a[], size_t start_idx, size_t end_idx, int value)
{
    if (start_idx > end_idx)
    {
        return -1;
    }
    size_t mid_idx = start_idx + (end_idx - start_idx) / 2; //"mittleren" indes finden

    // rekursionsanker, wenn der mid_index das gesuchte element ist wird er zurückgegeben
    if (a[mid_idx] == value)
    {
        return mid_idx;
    }

    if (a[start_idx] < a[end_idx]) // ist das element aufsteigend sortiert?
    {
        // rekursiver aufruf
        return (a[mid_idx] < value) ? bin_search_rec(a, mid_idx + 1, end_idx, value) : bin_search_rec(a, start_idx, mid_idx - 1, value);
    }
    else // für absteigend sortierte
    {
        return (a[mid_idx] < value) ? bin_search_rec(a, start_idx, mid_idx - 1, value) : bin_search_rec(a, mid_idx + 1, end_idx, value);
    }
}

int main()
{
    int a1[] = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    int a2[] = {10, 9, 8, 7, 5, 4, 3, 2, 1};

    printf("%ld, da 6 an 4.  Stelle im ersten Array ist\n", bin_search_rec(a1, 0, 8, 6));
    printf("%ld, da 5 nicht im ersten Array ist\n", bin_search_rec(a1, 0, 8, 5));
    printf("%ld, da 5 an 4. Stelle im ersten Array ist\n", bin_search_rec(a2, 0, 8, 5));
    printf("%ld, da 6 nicht im zweiten Array ist\n", bin_search_rec(a2, 0, 8, 6));

    return 0;
}
