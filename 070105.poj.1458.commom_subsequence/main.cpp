#include <iostream>
#include <string>
using namespace std;
int main() {
    string x, z;
    while (cin >> x >> z) {
        int length_x = x.length();
        int length_z = z.length();
        int **length = new int *[length_x + 1];
        for (int i = 0; i < length_x + 1; i++) {
            length[i] = new int[length_z + 1];
            for (int j = 0; j < length_z + 1; j++) {
                length[i][j] = 0;
            }
        }
        for (int i = 0; i < length_x; i++) {
            for (int j = 0; j < length_z; j++) {
                if (x[i] == z[j]) {
                    length[i + 1][j + 1] = length[i][j] + 1;
                } else {
                    length[i + 1][j + 1] = max(length[i][j + 1], length[i + 1][j]);
                }
            }
        }
        cout << length[length_x][length_z] << endl;
    }
}