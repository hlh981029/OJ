#include <cstring>
#include <iostream>

using namespace std;
int main() {
    int t, a, s, b, temp, mod = 1e6;
    int *family, **number;
    cin >> t >> a >> s >> b;
    family = new int[t];
    number = new int *[t + 1];
    memset(family, 0, sizeof(int) * t);
    for (int i = 0; i < a; i++) {
        cin >> temp;
        family[temp - 1]++;
    }
    for (int i = 0; i <= t; i++) {
        number[i] = new int[a + 1];
        number[i][0] = 1;
        for (int j = 1; j <= a; j++) {
            number[i][j] = 0;
        }
    }
    for (int i = 0; i < t; i++) {
        for (int j = 1; j <= a; j++) {
            if (j - 1 - family[i] >= 0) {
                number[i + 1][j] = (number[i + 1][j - 1] + number[i][j] - number[i][j - 1 - family[i]] + mod) % mod;
            } else {
                number[i + 1][j] = (number[i + 1][j - 1] + number[i][j]) % mod;
            }
        }
    }
    int ans = 0;
    for (int i = s; i <= b; i++) {
        ans += number[t][i];
    }
    cout << ans % mod;
}