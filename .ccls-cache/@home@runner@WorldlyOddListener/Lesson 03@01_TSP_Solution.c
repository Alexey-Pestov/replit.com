// Recap: Introduction to the Traveling Salesman Problem (TSP)
// Find the shortest route through all cities, starting and ending at city A such that no city is visited twice
// Assumptions: - Any two cities are directly connected; - Any city except A is visited once


#include <limits.h>
#include <stdio.h>

int shortest_path_length(int distances[4][4], int optPath[5]) {
int curOptPathLength = INT_MAX;
int city0 = 0;
for (int city1 = 1; city1 < 4; city1++) {
for (int city2 = 1; city2 < 4; city2++) {
for (int city3 = 1; city3 < 4; city3++) {
if (city1 != city2 && city1 != city3 && city2 != city3) {
int pathLength = distances[city0][city1] +
distances[city1][city2] +
distances[city2][city3] +
distances[city3][city0];
if (pathLength < curOptPathLength) {
curOptPathLength = pathLength;
  optPath[0] = city0;
  optPath[1] = city1;
  optPath[2] = city2;
  optPath[3] = city3;
  optPath[4] = city0;
}}}}}
return curOptPathLength;
}

int main() {
int distances[4][4];
int optPath[5];
printf("Input distances between 4 cities\n");
for (int from = 0; from < 4; from++) {
for (int to = from + 1; to < 4; to++) {
printf("Between cities %d and %d?\n", from, to);
scanf("%d", &distances[from][to]);
distances[to][from] = distances[from][to];
}}
int optPathLength = shortest_path_length(distances, optPath);
printf("Shortest path length: %d\n", optPathLength);
printf("Optimal path is:\n%d", optPath[0]);
for (int city = 1; city < 5; city++) {
  printf("->%d", optPath[city]);
}
return 0;
}

// gcc TSP_Solution.c -o P
// ./P