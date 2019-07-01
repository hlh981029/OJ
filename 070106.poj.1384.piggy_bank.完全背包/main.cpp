#include <algorithm>
#include <iostream>

using namespace std;
int main() {
    int max_int = 1e9;
    int t;
    cin >> t;
    for (int count = 0; count < t; count++) {
        int e, f, n;
        cin >> e >> f >> n;
        int size = f - e;
        int *w = new int[n];
        int *v = new int[n];
        int *amount = new int[size + 1];
        amount[0] = 0;
        for (int i = 1; i <= size; i++)
            amount[i] = max_int;
        for (int i = 0; i < n; i++) {
            cin >> v[i] >> w[i];
            for (int j = w[i]; j <= size; j++)
                amount[j] = min(amount[j], amount[j - w[i]] + v[i]);
        }
        if (amount[size] == 1e9)
            cout << "This is impossible." << endl;
        else
            cout << "The minimum amount of money in the piggy-bank is " << amount[size] << "." << endl;
    }
}