#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10][10] = { 0, };
pair<int, int> hole;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

// 0 is right 1 is down, 2 is left, 3 is up.

bool sameball(pair<int, int> ball, pair<int, int> newball) {
    if (ball.first == newball.first && ball.second == newball.second)
        return true;
    return false;
}

int whichfirst(pair<int, int> red, pair<int, int> blue, int dir) {
    int ret = 0;
    if (dir == 0) {
        if (blue.second > red.second)
            ret = 1;
    }
    else if (dir == 1) {
        if (blue.first > red.first)
            ret = 1;
    }
    else if (dir == 2) {
        if (blue.second < red.second)
            ret = 1;
    }
    else {
        if (blue.first < red.first)
            ret = 1;
    }
    return ret;
}// 0 is red first, 1 is blue first

pair<int, int> dirball(pair<int, int> ball, int ballnum, int dir) {
    int x, y;
    x = ball.first;
    y = ball.second;
    arr[x][y] = 0;
    while (arr[x + dx[dir]][y + dy[dir]] == 0) {
        x += dx[dir];
        y += dy[dir];
    }
    arr[x][y] = ballnum;
    if (arr[x + dx[dir]][y + dy[dir]] == 3) {
        arr[x][y] = 0;
        x += dx[dir];
        y += dy[dir];
    }
    ball = make_pair(x, y);
    return ball;
}

int DFS(pair<int, int> red, pair<int, int> blue, int num) {
    if (num > 10)
        return -1;
    if (blue.first == hole.first && blue.second == hole.second)
        return -1;
    else if (red.first == hole.first && red.second == hole.second) {
        return num;
    }
    int ret = -1;
    int a = -1;
    pair<int, int> newred, newblue;
    for (int i = 0; i < 4; i++) {
        if (whichfirst(red, blue, i) == 0) {
            newred = dirball(red, 1, i);
            newblue = dirball(blue, 2, i);
        }
        else {
            newblue = dirball(blue, 2, i);
            newred = dirball(red, 1, i);
        }
        //printf("%d %d %d %d\n", red.first, red.second, blue.first, blue.second);

        if (!sameball(red, newred) || !sameball(blue, newblue))
            a = DFS(newred, newblue, num + 1);

        arr[newred.first][newred.second] = 0;
        arr[newblue.first][newblue.second] = 0;
        arr[red.first][red.second] = 1;
        arr[blue.first][blue.second] = 2;
        arr[hole.first][hole.second] = 3;

        if (ret == -1)
            ret = a;
        else if (a != -1) {
            ret = min(ret, a);
        }
    }
    return ret;
}

int main(int argc, const char* argv[]) {
    int N, M, ans;
    char c;
    pair<int, int> r, b;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf(" %c", &c);
            if (c == '#') {
                arr[i][j] = -1;
            }
            else if (c == '.') {
                arr[i][j] = 0;
            }
            else if (c == 'R') {
                arr[i][j] = 1;
                r = make_pair(i, j);
            }
            else if (c == 'B') {
                arr[i][j] = 2;
                b = make_pair(i, j);
            }
            else if (c == 'O') {
                arr[i][j] = 3;
                hole = make_pair(i, j);
            }
        }
    }
    ans = DFS(r, b, 0);
    printf("%d\n", ans);
    return 0;
}