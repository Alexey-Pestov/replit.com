#include <stdio.h>

int maiin() {
int a, b, sum;
printf("Enter two integers: ");
scanf("%d %d", &a, &b);
sum = a + b;
printf("Sum = %d", sum);
return 0;
}