// Solving the Traveling Salesman Problem (TSP) using a recursive approach with memoization (also known as dynamic programming).

#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 20 // Define a reasonable limit for the number of cities

int tsp(int pos, int visited, int N, int distances[N][N], int dp[N][1<<MAX_CITIES], int optPath[N+1]) {
    if (visited == (1 << N) - 1) { // All cities visited
        return distances[pos][0]; // Return to the starting city
    }

    if (dp[pos][visited] != -1) { // Check if already computed
        return dp[pos][visited];
    }

    int minPath = INT_MAX;
    int nextCity = -1;

    for (int city = 0; city < N; city++) {
        if (!(visited & (1 << city))) { // If the city has not been visited
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

void reconstruct_path(int N, int optPath[N+1], int finalPath[N+1]) {
    int visited = 1;
    int current = 0;
    finalPath[0] = 0;

    for (int i = 1; i < N; i++) {
        current = optPath[current];
        finalPath[i] = current;
        visited |= (1 << current);
    }
    finalPath[N] = 0; // Return to starting city
}

int main() {
    int N;
    printf("Enter the number of cities: ");
    scanf("%d", &N);

    int distances[N][N];
    int dp[N][1 << MAX_CITIES];
    int optPath[N+1];   // To store the path order
    int finalPath[N+1]; // To reconstruct the path for printing

    // Initialize the dp array with -1 (indicating uncomputed states)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (1 << N); j++) {
            dp[i][j] = -1;
        }
    }

    printf("Input distances between cities\n");
    for (int from = 0; from < N; from++) {
        for (int to = from + 1; to < N; to++) {
            printf("Between cities %d and %d?\n", from, to);
            scanf("%d", &distances[from][to]);
            distances[to][from] = distances[from][to];
        }
    }

    int optPathLength = tsp(0, 1, N, distances, dp, optPath);
    reconstruct_path(N, optPath, finalPath);

    printf("Shortest path length: %d\n", optPathLength);
    printf("Optimal path is:\n%d", finalPath[0]);
    for (int i = 1; i <= N; i++) {
        printf("->%d", finalPath[i]);
    }
    printf("\n");

    return 0;
}
