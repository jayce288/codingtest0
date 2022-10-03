#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 100001

using namespace std;

int N, K;
bool visited[MAX_SIZE];

void BFS(int start) {
	int time = 0;
	queue<int> q; 
	q.push(start); 

	while (!q.empty()) {
		int size = q.size();
		
		for (int i = 0; i < size; i++) {
			int current = q.front();
			q.pop();

			if (current == K) {
				printf("%d", time);
				break;
			}
			if (current < 100000 && visited[current + 1] == 0) {
				int next = current + 1;
				q.push(next);
				visited[next] = 1;
			}
			if (current > 0 && visited[current - 1] == 0) {
				int next = current - 1;
				q.push(next);
				visited[next] = 1;
			}
			if (current*2 <= 100000 && visited[current*2] == 0) {
				int next = current * 2;
				q.push(next);
				visited[next] = 1;
			}
		}
		time++;
	}
}

int main() {
	scanf("%d %d", &N, &K);
	visited[N] = 1;
	BFS(N);

	return 0;
}