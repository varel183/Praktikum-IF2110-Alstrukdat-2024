// Varel Tiara
// 13523008
// Program BFS

#include <stdio.h>
#include <stdlib.h>
#include "queue.h" 
#include "boolean.h"

const int M = 100;
const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // Up, Down, Left, Right

int main() {
    int N;
    char arr[M][M];
    boolean visited[100][100] = {false};

    // Input the grid size
    scanf("%d", &N);

    // Read the grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }

    // Find starting and ending positions
    int startX, startY, endX, endY;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 'A') {
                startX = i;
                startY = j;
            } else if (arr[i][j] == 'B') {
                endX = i;
                endY = j;
            }
        }
    }

    ElType start = {startX, startY};
    ElType end = {endX, endY};

    // Initialize queue for BFS
    Queue q;
    CreateQueue(&q);
    enqueue(&q, start);

    visited[startX][startY] = true;
    int steps = 0;
    boolean found = false;

    // Perform BFS
    while (!isEmpty(q) && !found) {
        int size = length(q);  // Get the current layer size
        for (int i = 0; i < size; i++) {
            ElType current;
            dequeue(&q, &current);
            int x = current.row;
            int y = current.col;

            if (x == end.row && y == end.col) {
                found = true;
                break;
            }

            // Explore neighbors
            for (int d = 0; d < 4; d++) {
                int newX = x + directions[d][0];
                int newY = y + directions[d][1];

                if (newX >= 0 && newX < N && newY >= 0 && newY < N && arr[newX][newY] != '#' && !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    enqueue(&q, (ElType){newX, newY});
                }
            }
        }
        if (!found) steps++;
    }

    // Output result
    if (found) {
        printf("Ya\n%d\n", steps);
    } else {
        printf("Tidak\n");
    }

    return 0;
}
