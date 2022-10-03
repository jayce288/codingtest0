#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int DIV = 1000000;

string s;
long long dp[5001];
int num[5001];


int main() {
    cin >> s;
    int length = s.size();
    long long ans;

    for (int i = 0; i < length; i++) {
        num[i + 1] = s[i] - '0';
    }
    dp[0] = 1;
    dp[1] = 1;

    if (num[1] == 0) {
        cout << '0';
        return 0;
    }

    for (int i = 2; i <= length; i++) {
        if (num[i] == 0) {

            if (num[i - 1] == 1 || num[i - 1] == 2) {
                dp[i] = dp[i - 2];
                dp[i] %= DIV;
                continue;
            }
            else {
                cout << '0';
                return 0;
            }
        }
        if (num[i - 1] * 10 + num[i] <= 26 && num[i - 1] != 0) {
            dp[i] = dp[i - 2] + dp[i - 1];
            dp[i] %= DIV;
            continue;
        }
        dp[i] = dp[i - 1];
        dp[i] %= DIV;

    }
    ans = dp[length];
    ans %= DIV;

    cout << ans;
    return 0;
}