#include <iostream>
using namespace std;

int *par, *rank;

void init(int n) {
    par = new int[n];
    rank = new int[n];
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 0;
    }
}

int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (rank[x] < rank[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
    int n, k, t, x, y, ans = 0;
    cin >> n >> k;
    init(n * 3);
    for (int count = 0; count < k; count++) {
        scanf("%d%d%d", &t, &x, &y);
        x = x - 1;
        y = y - 1;
        if (x < 0 || x >= n || y < 0 || y >= n) {
            ans++;
        } else if (t == 1) {
            if (same(x, y + n) || same(x, y + 2 * n)) {
                ans++;
            } else {
                unite(x, y);
                unite(x + n, y + n);
                unite(x + 2 * n, y + 2 * n);
            }
        } else {
            if (same(x, y) || same(x, y + 2 * n)) {
                ans++;
            } else {
                unite(x, y + n);
                unite(x + n, y + 2 * n);
                unite(x + 2 * n, y);
            }
        }
    }
    cout << ans;
}