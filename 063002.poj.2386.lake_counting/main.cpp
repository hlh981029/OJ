#include <iostream>
using namespace std;
int n, m;
int field[100][100] = { 0 };
int offset_x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int offset_y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool mark(int x, int y, int count) {
    if (x >= n || x <0 || y < 0 || y >= m || field[x][y] != 0) {
        return false;
    }
    field[x][y] = count;
    for(int i = 0; i < 8; i++) {
        mark(x+offset_x[i], y+offset_y[i], count);
    }
    return true;
}

int main() {
    int number = 0;
    char status;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> status;
            if (status == 'W') {
                field[i][j] = 0;
            } else {
                field[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(mark(i, j, number+1)){
                number++;
            }
        }
    }
    cout << number;
}