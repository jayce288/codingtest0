#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int map[51][51];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1,0,1,0 };
int n, u, v, w, x, y;
int blocknum = 2;
int ans = 0;
vector<pair<int, int>> vec;
int main(void) {
    scanf("%d %d %d %d %d %d", &n, &u, &v, &w, &x, &y);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &map[i][j]);

    bool vv[50][50] = { false, };

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (map[i][j] == 1) {
                int minx = j, maxx = j, miny = i, maxy = i, blockcnt = 0;
                map[i][j] = blocknum;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                vv[i][j] = true;
               
                while (!q.empty()) {
                    int cy = q.front().first;
                    int cx = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];
                        if (0 <= nx && nx < n && 0 <= ny && ny < n && !vv[ny][nx] && map[ny][nx]) {
                            q.push(make_pair(ny, nx));
                            vv[ny][nx] = true;
                            map[ny][nx] = blocknum;
                            minx = min(minx, nx);
                            miny = min(miny, ny);
                            maxx = max(maxx, nx);
                            maxy = max(maxy, ny);
                        }
                    }
                }
                
                for (int posy = miny; posy <= maxy; ++posy)
                    for (int posx = minx; posx <= maxx; ++posx) {
                        if (map[posy][posx] == blocknum) ++blockcnt;
                        else if (map[posy][posx] != blocknum && map[posy][posx] != 0) blockcnt = -987654321;
                    }
                ++blocknum;
               
                if (((maxx - minx + 1) * (maxy - miny + 1)) - blockcnt != x * y) continue;
                int flag = -1;
                int side = 0;
               
                for (int k = minx + w; k < minx + w + y && k < maxx; ++k) {
                    if (!map[maxy][k]) flag = 2, ++side;
                }

                for (int k = minx + u - y - w; k < minx + u - w && k < maxx; ++k) {
                    if (!map[miny][k]) flag = 0, ++side;
                }

                for (int k = miny + u - y - w; k < miny + u - w && k < maxy; ++k) {
                    if (!map[k][maxx]) flag = 1, ++side;
                }

                for (int k = miny + w; k < miny + w + y && k < maxy; ++k) {
                    if (!map[k][minx]) flag = 3, ++side;
                }
                
                if (side != y) continue;
      
                switch (flag) {
                case 0:
                    if (miny - v >= 0 && maxx - minx + 1 == u) {
                        flag = -1;

                        for (int k = miny - 1; k >= miny - v; --k)
                            for (int l = minx; l <= maxx; ++l) {
                                if (map[k][l]) flag = 0;
                            }
                    }
                    break;
                case 1:
                    if (maxx + v <= n - 1 && maxy - miny + 1 == u) {
                        flag = -1;

                        for (int k = miny; k <= maxy; ++k)
                            for (int l = maxx + 1; l <= maxx + v; ++l) {
                                if (map[k][l]) flag = 0;
                            }
                    }
                    break;
                case 2:
                    if (maxy + v <= n - 1 && maxx - minx + 1 == u) {
                        flag = -1;

                        for (int k = maxy + 1; k <= maxy + v; ++k)
                            for (int l = minx; l <= maxx; ++l) {
                                if (map[k][l]) flag = 0;
                            }
                    }
                    break;
                case 3:
                    if (minx - v >= 0 && maxy - miny + 1 == u) {
                        flag = -1;

                        for (int k = miny; k <= maxy; ++k)
                            for (int l = minx - 1; l >= minx - v; --l) {
                                if (map[k][l]) flag = 0;
                            }
                    }
                    break;
                }

                if (flag == -1) {
                    ++ans;
                    vec.emplace_back(miny + 1, minx + 1);
                }
            }
        }

    printf("%d\n", ans);
    for (int i = 0; i < ans; ++i)
        printf("%d %d\n", vec[i].first, vec[i].second);
}