#include <stdio.h>

int binarySearch(int arr[], int size, int target)
{
    int left = 0, right = size - 1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (arr[middle] == target)
            return middle;

        if (arr[middle] < target)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Nummer nach der Gesucht werden soll: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);

    if (result != -1)
        printf("Element gefunden bei Index %d\n", result);
    else
        printf("Element nicht im Array gefunden.\n");

    return 0;
}
