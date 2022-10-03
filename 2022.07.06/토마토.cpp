#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

int graph[1000][1000];
queue<pair<int, int>> q;
int result = 0;
int M, N;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (graph[nx][ny] == 0) {
                    graph[nx][ny] = graph[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &M, &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 1) {
                q.push(make_pair(i, j));
            }
        }
    }

    bfs();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == 0) {
                printf("-1\n");
                return 0;
            }

            if (result < graph[i][j]) {
                result = graph[i][j];
            }
        }
    }

    printf("%d\n", result - 1);
    return 0;
}
