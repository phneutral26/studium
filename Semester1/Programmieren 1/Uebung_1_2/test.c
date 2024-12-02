#include<stdio.h>

int main(void){
    char name[10];
    printf("Enter your first Name: ");
    scanf("%s", name);
    printf("Hello %s!\n", name);
    return 0;
}