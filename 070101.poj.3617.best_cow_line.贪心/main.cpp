#include <algorithm>
#include <iostream>

using namespace std;
int main() {
    int n;
    cin >> n;
    char *previous, *current;
    previous = new char[n];
    current = new char[n];
    for (int i = 0; i < n; i++) {
        cin >> previous[i];
    }
    int head = 0;
    int tail = n - 1;
    for (int i = 0; i < n; i++) {
        if (previous[head] > previous[tail]) {
            current[i] = previous[tail--];
        } else if (previous[head] < previous[tail]) {
            current[i] = previous[head++];
        } else {
            int level = 1;
            while (level < (tail - head) / 2 && previous[head + level] == previous[tail - level]) {
                level++;
            }
            if (previous[head + level] < previous[tail - level]) {
                current[i] = previous[head++];
            } else {
                current[i] = previous[tail--];
            }
        }
        if (i != 0 && i % 80 == 0) {
            cout << endl;
        }
        cout << current[i];
    }
}