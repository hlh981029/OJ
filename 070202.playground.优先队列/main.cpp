#include <iostream>
#include <queue>
using namespace std;
int heap[100], size = 0;
void push(int x) {
    int i = size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] <= x)
            break;
        heap[i] = heap[p];
        i = p;
    }
    heap[i] = x;
}
int pop() {
    int ret = heap[0];
    int x = heap[--size];
    int i = 0;
    while (i * 2 + 1 < size) {
        int a = i * 2 + 1, b = i * 2 + 2;
        if (b < size && heap[b] < heap[a])
            a = b;
        if (heap[a] >= x)
            break;
        heap[i] = heap[a];
        i = a;
    }
    heap[i] = x;
    return ret;
}
void print() {
    for (int i = 0; i < size; i++)
        cout << heap[i] << ' ';
    cout << endl;
}
void test_heap() {
    push(1);
    push(3);
    push(2);
    push(4);
    push(0);
    push(8);
    print();
    pop();
    print();
    pop();
    print();
    pop();
    print();
}
int main() {
    priority_queue<int> pqueue;
    pqueue.push(3);
    pqueue.push(5);
    pqueue.push(1);
    while (!pqueue.empty()) {
        cout << pqueue.top() << endl;
        pqueue.pop();
    }
    return 0;
}