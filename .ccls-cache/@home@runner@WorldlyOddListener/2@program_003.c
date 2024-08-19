#include <stdio.h>
int main() {
int N, value, sum = 0;
printf("How many number to add?\n");
scanf("%d", &N);
printf("Enter %d integers\n", N);
for(int i=1; i<=N; i++){
scanf("%d", &value);
sum = sum + value;
}
printf("Sum = %d", sum);
return 0;
}