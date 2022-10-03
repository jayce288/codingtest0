#pragma warning(disable:4996)
#include <stdio.h>
#include <vector>
#include<cmath>
#define MAX 4000000

using namespace std;
int N, sum;
int check[MAX + 1];
vector<int> prime_sum;

int main() {

	scanf("%d", &N);
	prime_sum.push_back(0);

	for (int i = 2; i < sqrt(MAX); i++) {
		if (check[i]) {
			continue;
		}
		for (int j = 2 * i; j <= MAX; j += i)
			check[j] = 1;  
	}

	for (int i = 2; i <= MAX; i++) {
		if (check[i] == 0) {
			sum += i;
			prime_sum.push_back(sum);
		}
	}

	int ans, left, right;
	ans = 0;
	left = 0;
	right = 0;

	while (left <= right && right < prime_sum.size()) {
		if (prime_sum[right] - prime_sum[left] > N) {
			left++;
		}
		else if (prime_sum[right] - prime_sum[left] < N) {
			right++;
		}
		else {
			ans++;
			right++;
		}
	}

	printf("%d", ans);

	return 0;
}

