#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    freopen("input.in", "r", stdin);
    int a[4][4];
    for (int i = 0; i < 4; i++) {
        // int temp[4];
        for (int j = 0; j < 4; j++) {
            // int e;
            cin >> a[i][j];
            // temp[j] = e;
        }
        // a[i] = temp;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
