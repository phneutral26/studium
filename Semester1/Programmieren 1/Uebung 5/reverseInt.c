#include <stdio.h>

int reverseInteger(int *num);

int main (int argc, char *argv[]) {
    int num = 12314;

    printf("Ursprünglicher Integer: %d\n", num);
    reverseInteger(&num);
    printf("Umgekehrter Integer: %d\n", num);
    return 0;
}

int reverseInteger(int *num) {
    int reversedNum = 0;

    while (*num!=0) {
        reversedNum = reversedNum * 10 + *num % 10;
        *num /= 10;
    }

    *num = reversedNum;
    return reversedNum;
}
    