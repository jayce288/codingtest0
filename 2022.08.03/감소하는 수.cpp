#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <long long> v;

void calculate(long long num) {
	if (num > 9876543210)
		return;

	v.push_back(num);
	for (int i = 0; i < 10; i++) {
		if (num % 10 > i) {
			calculate(num * 10 + i);
		}
	}
}

int main() {
	int N;

	scanf("%d", &N);

	if (N < 10) {
		printf("%d", N);
	}
	else {
		for (int i = 0; i < 10; i++) {
			calculate(i);
		}
		sort(v.begin(),v.end());

		if (v.size() <= N)
			printf("-1");
		else
			printf("%lld", v[N]);
	}
	return 0;
}