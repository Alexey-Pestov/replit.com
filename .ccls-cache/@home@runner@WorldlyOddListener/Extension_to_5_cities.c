#include <limits.h>
#include <stdio.h>

int shortest_path_length(int distances[5][5], int optPath[6]) {
int curOptPathLength = INT_MAX;
int city0 = 0;
for (int city1 = 1; city1 < 5; city1++) {
for (int city2 = 1; city2 < 5; city2++) {
for (int city3 = 1; city3 < 5; city3++) {
for (int city4 = 1; city4 < 5; city4++) {
if (city1 != city2 && city1 != city3 && city1 != city4 && city2 != city3 && city2 != city4 && city3 != city4) {
int pathLength = distances[city0][city1] +
distances[city1][city2] +
distances[city2][city3] +
distances[city3][city4] +
distances[city4][city0];
if (pathLength < curOptPathLength) {
curOptPathLength = pathLength;
  optPath[0] = city0;
  optPath[1] = city1;
  optPath[2] = city2;
  optPath[3] = city3;
  optPath[4] = city4;
  optPath[5] = city0;
}}}}}}
return curOptPathLength;
}

int main() {
int distances[5][5];
int optPath[6];
printf("Input distances between 5 cities\n");
for (int from = 0; from < 5; from++) {
for (int to = from + 1; to < 5; to++) {
printf("Between cities %d and %d?\n", from, to);
scanf("%d", &distances[from][to]);
distances[to][from] = distances[from][to];
}}
int optPathLength = shortest_path_length(distances, optPath);
printf("Shortest path length: %d\n", optPathLength);
printf("Optimal path is:\n%d", optPath[0]);
for (int city = 1; city < 6; city++) {
  printf("->%d", optPath[city]);
}
return 0;
}

// gcc Extension_to_5_cities.c -o P
// ./P