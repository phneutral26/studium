#include <stdio.h>

unsigned long long
euclid_recursive(unsigned long long num1, unsigned long long num2)
{
  if (num2 == 0) {
    return num1;
  } else {
    return euclid_recursive(num2, num1 % num2);
  }
}

unsigned long long
euclid_iterative(unsigned long long num1, unsigned long long num2)
{
  while (num2 != 0) {
    unsigned long long temp = num2;
    num2 = num1 % num2;
    num1 = temp;
  }
  return num1;
}

int
main()
{
  unsigned long long num1 = 121, num2 = 44;

  printf("Rekursiver ggT von %llu und %llu: %llu\n",
         num1,
         num2,
         euclid_recursive(num1, num2));
  printf("Iternum1tiver ggT von %llu und %llu: %llu\n",
         num1,
         num2,
         euclid_iterative(num1, num2));

  return 0;
}