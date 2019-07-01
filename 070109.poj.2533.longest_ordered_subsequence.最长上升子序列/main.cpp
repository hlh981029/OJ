#include <algorithm>
#include <iostream>

using namespace std;
int a[1000];
int length[1001];
int n;
int main() {
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        length[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                length[i] = max(length[i], length[j] + 1);
            }
        }
        ans = max(ans, length[i]);
    }
    cout << ans;
}