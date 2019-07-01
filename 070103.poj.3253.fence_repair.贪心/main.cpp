#include <algorithm>
#include <iostream>

using namespace std;
int main() {
    int n;
    cin >> n;
    int *plank = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> plank[i];
    }
    if (n == 1) {
        cout << plank[0];
        return 0;
    }
    int min1 = 0;
    int min2 = 1;
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        min1 = i;
        min2 = i + 1;
        for (int j = i + 1; j < n; j++) {
            if (plank[min1] > plank[j]) {
                min2 = min1;
                min1 = j;
            } else if (plank[min2] > plank[j]) {
                min2 = j;
            }
        }
        int two_sum = plank[min1] + plank[min2];
        plank[min1] = two_sum;
        swap(plank[i], plank[min2]);
        ans += two_sum;
    }
    cout << ans;
}