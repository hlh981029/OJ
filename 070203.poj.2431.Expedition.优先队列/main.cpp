#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;
typedef pair<int, int> station;
int main() {
    int n, l, p;
    cin >> n;
    station *stations = new station[n + 1];
    for (int i = 0; i < n; i++)
        cin >> stations[i].first >> stations[i].second;
    cin >> l >> p;
    for (int i = 0; i < n; i++)
        stations[i].first = l - stations[i].first;
    sort(stations, stations + n);
    stations[n].first = l;
    stations[n].second = 0;
    priority_queue<int> pqueue;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        while (p < stations[i].first && !pqueue.empty()) {
            p += pqueue.top();
            pqueue.pop();
            ans++;
        }
        if (p < stations[i].first) {
            break;
        } else {
            pqueue.push(stations[i].second);
        }
    }
    if (p < l) {
        cout << -1;
    } else {
        cout << ans;
    }
}