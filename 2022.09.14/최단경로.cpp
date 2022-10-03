#pragma warning(disable:4996)
#include <stdio.h>
#include <vector>
#include <queue>
# define INF 99999999
#define MAX 20010

using namespace std;

int V, E, start;
int Dist[MAX]; 
vector<pair<int, int>> Vertex[MAX];

void Dijkstra_Using_Heap() {
	priority_queue<pair<int, int>> PQ;
	PQ.push(make_pair(0, start));
	Dist[start] = 0;

	while (PQ.empty() == 0) { 
		int Cost = -PQ.top().first;
		int Cur = PQ.top().second;
		PQ.pop();
		for (int i = 0; i < Vertex[Cur].size(); i++) { 
			int Next = Vertex[Cur][i].first;
			int nCost = Vertex[Cur][i].second;
			if (Dist[Next] > Cost + nCost) { 
				Dist[Next] = Cost + nCost;
			    PQ.push(make_pair(-Dist[Next], Next));
			} 
		} 
	}
	for (int i = 1; i <= V; i++) { 
		if (Dist[i] == INF) 
			printf("INF\n");
		else 
			printf("%d\n", Dist[i]);
	} 
}

int main() {
	scanf("%d %d", &V, &E);
	scanf("%d", &start);

	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		Vertex[a].push_back(make_pair(b, c));
	}
	for (int i = 1; i <= V; i++) 
		Dist[i] = INF;

	Dijkstra_Using_Heap();

	return 0;
}