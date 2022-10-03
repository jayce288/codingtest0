#pragma warning(disable:4996)
#include <iostream>
#include <deque>
#define MAX_SIZE 500

using namespace std;

int M, N;
int map[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int dfs(int x,int y) {
    if (x == M - 1 && y == N - 1)
        return 1;

    if(dp[x][y] != -1)
        return dp[x][y];
    
    dp[x][y] = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
            if (map[nx][ny] < map[x][y]) {
                dp[x][y] = dp[x][y] + dfs(nx, ny);
            }
        }
    }

    return dp[x][y];
}


int main() {
    scanf("%d %d", &M, &N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
            scanf("%d", &map[i][j]);
        }
    }
	
    int result = dfs(0, 0);

    printf("%d", result);

	return 0;
}