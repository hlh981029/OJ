#include <algorithm>
#include <iostream>

using namespace std;
int main() {
    int r, n;
    int x[1000];
    while (true) {
        cin >> r >> n;
        if (r == -1 && n == -1)
            break;
        for (int i = 0; i < n; i++)
            cin >> x[i];
        sort(x, x + n);
        int start = 0;
        int current = 0;
        int number = 0;
        while (current != n) {
            start = current;
            while (current < n && x[current] - x[start] <= r)
                current++;
            start = current - 1;
            while (current < n && x[current] - x[start] <= r)
                current++;
            number++;
        }
        cout << number << endl;
    }
}