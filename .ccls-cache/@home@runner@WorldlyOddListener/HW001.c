// Read integers x and y. Given coordinate of the cell (x,y) on the chessboard, determine the color of the cell.
// Шахматная доска представляет собой чередование черных и белых клеток. Клетка будет черной, если сумма её координат чётная, и белой, если нечетная.

#include <stdio.h>

int main() {
    int x, y;

    printf("Enter coordinates x and y: ");
    if (scanf("%d %d", &x, &y) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    if ((x + y) % 2 == 0) {
        printf("The cell (%d, %d) is black.\n", x, y);
    } else {
        printf("The cell (%d, %d) is white.\n", x, y);
    }

    return 0;
}

// gcc HW001.c -o HW1
// ./HW1