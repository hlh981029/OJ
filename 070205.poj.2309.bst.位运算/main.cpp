#include <iostream>
using namespace std;
int main() {
    int n, x, d;
    cin >> n;
    while (n--) {
        cin >> x;
        d = (x & -x) - 1;
        cout << x - d << ' ' << x + d << endl;
    }
}
