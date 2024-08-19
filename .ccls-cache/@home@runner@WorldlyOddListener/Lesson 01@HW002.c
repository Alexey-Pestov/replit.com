// Read integers x1, y1, x2, y2, x3, y3. Compute square area of the triangle formed by three points (x1,y1), (x2,y2), (x3,y3).

#include <stdio.h>
#include <stdlib.h>  // Для функции abs()

int main() {
    int x1, y1, x2, y2, x3, y3;
    int area;

    // Считываем координаты трёх вершин треугольника
    printf("Enter the coordinates of the first point (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the coordinates of the second point (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    printf("Enter the coordinates of the third point (x3 y3): ");
    scanf("%d %d", &x3, &y3);

    // Вычисляем площадь треугольника по формуле
    area = abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2;

    // Выводим результат
    printf("The area of the triangle is: %d\n", area);

    return 0;
}

// gcc HW002.c -o HW2
// ./HW2