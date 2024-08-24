// Solving the Traveling Salesman Problem (TSP) using a recursive approach with memoization (also known as dynamic programming).

#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10 // Максимальное количество городов

int tsp(int pos, int visited, int N, int distances[MAX_CITIES][MAX_CITIES], int dp[MAX_CITIES][1<<MAX_CITIES], int optPath[MAX_CITIES]) {
    if (visited == (1 << N) - 1) { // Все города посещены
        return distances[pos][0]; // Возвращаемся в начальный город
    }

    if (dp[pos][visited] != -1) { // Если уже вычислено
        return dp[pos][visited];
    }

    int minPath = INT_MAX;
    int nextCity = -1;

    for (int city = 0; city < N; city++) {
        if (!(visited & (1 << city))) { // Если город еще не посещен
            int newPath = distances[pos][city] + tsp(city, visited | (1 << city), N, distances, dp, optPath);
            if (newPath < minPath) {
                minPath = newPath;
                nextCity = city;
            }
        }
    }

    optPath[pos] = nextCity;
    return dp[pos][visited] = minPath;
}

void reconstruct_path(int N, int optPath[MAX_CITIES], int finalPath[MAX_CITIES + 1]) {
    int visited = 1;
    int current = 0;
    finalPath[0] = 0;

    for (int i = 1; i < N; i++) {
        current = optPath[current];
        finalPath[i] = current;
        visited |= (1 << current);
    }
    finalPath[N] = 0; // Возвращаемся в начальный город
}

int main() {
    int N;
    printf("Введите количество городов (не более %d): ", MAX_CITIES);
    scanf("%d", &N);

    if (N > MAX_CITIES) {
        printf("Число городов превышает допустимое значение %d\n", MAX_CITIES);
        return 1;
    }

    int distances[MAX_CITIES][MAX_CITIES];
    int dp[MAX_CITIES][1 << MAX_CITIES];
    int optPath[MAX_CITIES];
    int finalPath[MAX_CITIES + 1];

    // Инициализация массива dp значением -1 (невычисленные состояния)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (1 << N); j++) {
            dp[i][j] = -1;
        }
    }

    printf("Введите расстояния между городами\n");
    for (int from = 0; from < N; from++) {
        for (int to = from + 1; to < N; to++) {
            printf("Между городами %d и %d?\n", from, to);
            scanf("%d", &distances[from][to]);
            distances[to][from] = distances[from][to];
        }
    }

    int optPathLength = tsp(0, 1, N, distances, dp, optPath);
    reconstruct_path(N, optPath, finalPath);

    printf("Длина кратчайшего пути: %d\n", optPathLength);
    printf("Оптимальный путь:\n%d", finalPath[0]);
    for (int i = 1; i <= N; i++) {
        printf("->%d", finalPath[i]);
    }
    printf("\n");

    return 0;
}

// Объяснение:
// Ограничение на количество городов: Мы явно задаем ограничение на 𝑁 через MAX_CITIES, равное 10.
// Статические массивы: Используем массивы фиксированного размера, которые занимают столько памяти, сколько нужно для обработки до 10 городов. Это упрощает управление памятью.
// Рекурсивная функция: Алгоритм использует рекурсию с мемоизацией для поиска кратчайшего пути, сохраняя промежуточные результаты в массиве dp.
// Вывод результатов: Программа выводит длину кратчайшего пути и сам путь.
// Этот код предназначен для использования при 𝑁≤10 и не должен приводить к проблемам с выделением памяти или сегментационным ошибкам.

// gcc 04_TSP_using_recursive_approach.c -o P
// ./P