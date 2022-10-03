#include <iostream>
#include <cmath>
using namespace std;
int weight[31], dp[31][15001];
int n, k;

void DP(int i, int w) {
    if (n < i || dp[i][w])
        return;

    dp[i][w] = 1;
    DP(i + 1, w);
    DP(i + 1, w + weight[i]);
    DP(i + 1, abs(w - weight[i]));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    DP(0, 0);

    cin >> k;
    for (int i = 0; i < k; i++) {
        int bead;
        cin >> bead;
        if (bead > 15000)
            cout << "N ";
        else if (dp[n][bead])
            cout << "Y ";
        else
            cout << "N ";
    }
}