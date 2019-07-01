#include <iostream>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

typedef pair<int, int> position;
queue<position *> pos_queue;
position last[40][40];
int maze[40][40];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;

void bfs(int i, int j) {
    maze[0][0] = 1;
    position *front, *next, *p = new position(0, 0);
    int newx, newy;
    pos_queue.push(p);
    while (!pos_queue.empty()) {
        front = pos_queue.front();
        for (int i = 0; i < 4; i++) {
            newx = front->first + dx[i];
            newy = front->second + dy[i];
            if (newx >= 0 && newx <= n && newy >= 0 && newy <= m && maze[newx][newy] == 0) {
                next = new position(newx, newy);
                last[newx][newy] = *front;
                maze[newx][newy] = maze[front->first][front->second] + 1;
                pos_queue.push(next);
                if (newx == n - 1 && newy == m - 1) {
                    return;
                }
            }
        }
        pos_queue.pop();
    }
}

int main() {
    n = m = 5;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> maze[i][j];
        }
    }
    bfs(0, 0);
    position p(n - 1, n - 1), zero(0, 0);
    stack<position> pos_stack;
    while (p != zero) {
        pos_stack.push(last[p.first][p.second]);
        p = last[p.first][p.second];
    }
    while (!pos_stack.empty()) {
        p = pos_stack.top();
        printf("(%d, %d)\n", p.first, p.second);
        pos_stack.pop();
    }
    printf("(%d, %d)\n", n - 1, m - 1);
    // printf("%d", maze[n - 1][m - 1]);
}
