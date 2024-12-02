#include <stdio.h>

int reverseInteger(int *num);

int main() {
    int num = 12345;
    int expected = 54321;
    int result = reverseInteger(&num);

    if (result == expected && num == expected) {
        printf("Test passed: reverseInteger correctly reversed %d to %d\n", 12345, result);
    } else {
        printf("Test failed: Expected %d, but got %d\n", expected, result);
    }
    return 0;
}

#include "reverseInt.c"
