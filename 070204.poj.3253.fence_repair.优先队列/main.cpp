#include <iostream>
using namespace std;
int *plank;
int size = 0;

void push(int x) {
    int pos = size++;
    int t;
    while (pos > 0) {
        t = (pos - 1) / 2;
        if (plank[t] <= x) {
            break;
        }
        plank[pos] = plank[t];
        pos = t;
    }
    plank[pos] = x;
}

int pop() {
    int ans = plank[0];
    int max = plank[--size];
    int pos = 0;
    int t = pos * 2 + 1;
    while (t < size) {
        if (t + 1 < size && plank[t + 1] < plank[t]) {
            t = t + 1;
        }
        if (max > plank[t]) {
            plank[pos] = plank[t];
            pos = t;
            t = t * 2 + 1;
        } else {
            break;
        }
    }
    plank[pos] = max;
    return ans;
}

int main() {
    int n, t;
    cin >> n;
    plank = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> t;
        push(t);
    }
    if (size == 1) {
        cout << plank[0];
        return 0;
    }
    int min1, min2;
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        min1 = pop();
        min2 = pop();
        ans += min1 + min2;
        push(min1 + min2);
    }
    cout << ans;
}
