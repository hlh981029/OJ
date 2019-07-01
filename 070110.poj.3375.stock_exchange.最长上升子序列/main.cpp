#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;
int n;
int a[100000];
int index[100000];
int find(int start, int end, int n) {
    if (start == end)
        return start;
    int middle = (end + start) / 2;
    if (n > index[middle])
        return find(middle + 1, end, n);
    else
        return find(start, middle, n);
}

int main() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            index[i] = 1e9;
        }
        for (int i = 0; i < n; i++) {
            index[find(0, n - 1, a[i])] = a[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            if (index[i] != 1e9) {
                cout << i + 1 << endl;
                break;
            }
        }
    }
}