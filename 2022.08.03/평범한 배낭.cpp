#pragma warning(disable:4996)
#include<iostream>
#include <stdio.h>
#include<algorithm>
using namespace std;

int N, K;
int dp[101][100001];
int W[101];
int V[101];

int main() {
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++)
		scanf("%d %d", &W[i], &V[i]);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - W[i] >= 0) 
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			else 
				dp[i][j] = dp[i - 1][j];
		}
	} 

	printf("%d", dp[N][K]);

}
