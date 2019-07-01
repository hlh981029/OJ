#include <algorithm>
#include <iostream>

using namespace std;
int main() {
    int divide[11][11] = {0};
    int t;
    int m, n;
    cin >> t;
    for (int count = 0; count < t; count++) {
        cin >> m >> n;
        divide[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (j >= i) {
                    divide[i][j] = divide[i][j - i] + divide[i - 1][j];
                } else {
                    divide[i][j] = divide[i - 1][j];
                }
            }
        }
        cout << divide[n][m] << endl;
    }
}