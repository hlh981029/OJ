#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int count = 0; count < t; count++) {
        int total, year, bond_numbers;
        cin >> total >> year >> bond_numbers;
        int *value = new int[bond_numbers];
        int *interest = new int[bond_numbers];
        for (int i = 0; i < bond_numbers; i++) {
            cin >> value[i] >> interest[i];
        }
        for (int count_year = 0; count_year < year; count_year++) {
            int *money = new int[total / 1000 + 1];
            for (int i = 0; i < total / 1000 + 1; i++) {
                money[i] = 0;
            }
            for (int i = 0; i < bond_numbers; i++) {
                for (int j = value[i] / 1000; j <= total / 1000; j++) {
                    money[j] = max(money[j], money[j - value[i] / 1000] + interest[i]);
                }
            }
            total += money[total / 1000];
            delete[] money;
        }
        cout << total << endl;
    }
}