#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;

int map[101][101];
int visit[101][101];
int max_v;

int cnt;

int dx[] = { 1,0,0,-1 };
int dy[] = { 0,1,-1,0 };

void initial() {

	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = 0;
		}
	}
}

void dfs(int x, int y, int loop) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (map[nx][ny] > loop && visit[nx][ny] == 0) {
			visit[nx][ny] = 1;
			dfs(nx, ny, loop);
		}
	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (i == 0 && j == 0) {
				max_v = map[i][j];
			}
			if (map[i][j] > max_v)max_v = map[i][j];

		}
	}

	vector<int> ans;
	int loop_value = 0;
	while (loop_value <= max_v) {

		initial();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] > loop_value && visit[i][j] == 0) {
					cnt++;
					visit[i][j] = 1;
					dfs(i, j, loop_value);

				}
			}
		}

		ans.push_back(cnt);
		loop_value++;
	}

	//for (int i = 0; i < ans.size(); i++) {
	//	cout << ans[i] << " ";
	//}


	cout << *max_element(ans.begin(), ans.end());



	return 0;
}