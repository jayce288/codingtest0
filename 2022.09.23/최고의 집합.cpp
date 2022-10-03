#include<iostream> 
#include<string>
#include<vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if (n > s) {
        return { -1 };
    }

    int a = s / n;
    int b = s % n;

    for (int i = 0; i < n; i++) {
        if (i >= n - b) {
            answer.push_back(a + 1);
        }
        else {
            answer.push_back(a);
        }
    }

    return answer;
}