#include "dyn_array.h"
#include <stdio.h>

int main() {
    dyn_array *arr = create_array(2);

    if (!arr) {
        printf("Failed to create array\n");
        return 1;
    }

    append(arr, 10);
    append(arr, 20);
    append(arr, 30);
    append(arr, 40);
    append(arr, 50);
    print_array(arr);

    int value;
    if (get(arr, 1, &value) == DYN_ARRAY_SUCCESS) {
        printf("Element at index 1: %d\n", value);
    }

    set(arr, 1, 50);
    printf("Array nachdem Index 1 auf 50 gesetzt wurde:\n");
    print_array(arr);

    remove_at(arr, 0);
    printf("Array nach dem Element am Index 0 gelöscht wurde:\n");
    print_array(arr);

    printf("Array 'size': %zu\n", size(arr));
    printf("Array 'capacity': %zu\n", capacity(arr));

    destroy_array(arr);
    return 0;
}
