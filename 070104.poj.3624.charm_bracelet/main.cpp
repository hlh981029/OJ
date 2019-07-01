#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
int dp[12880];
int weight[3402];
int value[3402];

int n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= 0; j--) {
            if (j >= weight[i]) {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
    }
    cout << dp[m];
}