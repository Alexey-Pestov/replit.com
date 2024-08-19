#include <stdio.h>
int main() {
int x;
scanf('%d', &x);
if (x <= 1) {
printf('%d is NOT prime\n', x);
return 0;
}

for (int i=2; i<x; i++)
if (x % i == 0) {
printf('%d is NOT prime\n', x);
return 0;
}
printf('%d is prime\n', x);
return 0;
}