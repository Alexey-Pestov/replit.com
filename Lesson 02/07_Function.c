// Function

#include <stdio.h>

int calculate_sum(int a[5]) {
int s = 0;
for (int i = 0; i < 5; i++) {
s += a[i];
}
return s;
}

int main() {
int numbers[5];
for (int i = 0; i < 5; i++) {
scanf("%d", &numbers[i]);
}

int sum = calculate_sum(numbers);
printf("The sum is %d", sum);
return 0;
}

// gcc Function.c -o P1
// ./P1