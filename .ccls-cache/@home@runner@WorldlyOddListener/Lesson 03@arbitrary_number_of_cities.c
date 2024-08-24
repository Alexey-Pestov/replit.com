#include <stdio.h>
#include <limits.h>

void shortest_path_length(int N, int distances[N][N], int optPath[N+1]) {
    int curOptPathLength = INT_MAX;

    int perm[N-1];
    for (int i = 0; i < N-1; i++) {
        perm[i] = i + 1;
    }

    do {
        int pathLength = distances[0][perm[0]];
        for (int i = 0; i < N-2; i++) {
            pathLength += distances[perm[i]][perm[i+1]];
        }
        pathLength += distances[perm[N-2]][0];

        if (pathLength < curOptPathLength) {
            curOptPathLength = pathLength;
            optPath[0] = 0;
            for (int i = 0; i < N-1; i++) {
                optPath[i+1] = perm[i];
            }
            optPath[N] = 0;
        }
    } while (next_permutation(perm, N-1));

    printf("Shortest path length: %d\n", curOptPathLength);
    printf("Optimal path is:\n%d", optPath[0]);
    for (int city = 1; city < N+1; city++) {
        printf("->%d", optPath[city]);
    }
    printf("\n");
}

int next_permutation(int *array, int length) {
    int i = length - 1;
    while (i > 0 && array[i-1] >= array[i]) {
        i--;
    }
    if (i <= 0) return 0;

    int j = length - 1;
    while (array[j] <= array[i-1]) {
        j--;
    }

    int temp = array[i-1];
    array[i-1] = array[j];
    array[j] = temp;

    j = length - 1;
    while (i < j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
    return 1;
}

int main() {
    int N;
    printf("Enter the number of cities: ");
    scanf("%d", &N);

    int distances[N][N];
    int optPath[N+1];

    printf("Input distances between cities\n");
    for (int from = 0; from < N; from++) {
        for (int to = from + 1; to < N; to++) {
            printf("Between cities %d and %d?\n", from, to);
            scanf("%d", &distances[from][to]);
            distances[to][from] = distances[from][to];
        }
    }

    shortest_path_length(N, distances, optPath);
    return 0;
}

// Explanation:
// Dynamic City Count: The number of cities 𝑁 is input by the user, and the program dynamically adjusts to handle any number of cities.
// Permutations: The program generates permutations of cities (excluding the starting city) to find the shortest path. The function next_permutation is used to generate the next permutation of cities.
// Path Calculation: For each permutation, the program calculates the total path length and checks if it's the shortest one found so far.
// Output: Finally, the program outputs the shortest path length and the corresponding city order.

// This approach is feasible for small values of  𝑁 because it checks every possible path (brute force). For large 𝑁, you would need more efficient algorithms like dynamic programming or heuristic methods.

// gcc arbitrary_number_of_cities.c -o P
// ./P