#include <algorithm>
#include <iostream>

using namespace std;
int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            return 0;
        }
        int ans = 0;
        int *value = new int[n];
        int *amount = new int[n];
        int *number = new int[m + 1];
        number[0] = 0;
        for (int i = 0; i < n; i++) {
            cin >> value[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> amount[i];
        }
        for (int i = 1; i <= m; i++) {
            number[i] = -1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                if (number[j] >= 0) {
                    number[j] = amount[i];
                } else if (j < value[i] || number[j - value[i]] <= 0) {
                    number[j] = -1;
                } else {
                    number[j] = number[j - value[i]] - 1;
                }
            }
        }
        for (int j = 1; j <= m; j++) {
            if (number[j] >= 0) {
                ans++;
            }
        }
        cout << ans << endl;
    }
}