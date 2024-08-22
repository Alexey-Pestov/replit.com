#include <stdio.h>

int main() {
int intNumbers[5] = {1, 2, 3, 4, 5};

for (int i = 0; i < 5; i++) {
printf("%d ", intNumbers[i]);
}

printf("\n");
return 0;
}

// gcc program_003.c -o P1
// ./P1