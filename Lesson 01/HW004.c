// Read float numbers a, b and c, which represent lengths of the sides of a triangle. Using this information compute all three angles of the triangle in radians
// Чтобы вычислить углы треугольника по длинам его сторон a, b и c, можно использовать теорему косинусов.

#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    float alpha, beta, gamma;

    // Считываем длины сторон треугольника
    printf("Enter the lengths of the sides a, b, and c: ");
    if (scanf("%f %f %f", &a, &b, &c) != 3) {
        printf("Invalid input.\n");
        return 1;
    }

    // Проверяем, можно ли построить треугольник с такими сторонами
    if (a + b > c && a + c > b && b + c > a) {
        // Вычисляем углы в радианах
        alpha = acos((b*b + c*c - a*a) / (2 * b * c));
        beta  = acos((a*a + c*c - b*b) / (2 * a * c));
        gamma = acos((a*a + b*b - c*c) / (2 * a * b));

        // Выводим углы
        printf("Angle alpha (opposite to side a) = %.6f radians\n", alpha);
        printf("Angle beta (opposite to side b) = %.6f radians\n", beta);
        printf("Angle gamma (opposite to side c) = %.6f radians\n", gamma);
    } else {
        printf("The given lengths do not form a valid triangle.\n");
    }

    return 0;
}

// gcc HW004.c -o HW4 -lm
// ./HW4