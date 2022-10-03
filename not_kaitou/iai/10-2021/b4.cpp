#include <bits/stdc++.h>
using namespace std;
struct pos {
    int a[5], v;
    bool operator<(const pos other) const {
        int s = 0;
        for (int i = 0; i < 5; i++) s += (a[i] < other.a[i]);
        return s > 2;
    }
};
int main() {
    int n;
    cin >> n;
    pos p[n];
    int input;
    for (int ii = 0; ii < 5; ii++) {
        // cout << ii << " ";
        for (int j = 0; j < n; j++) {
            cin >> input;
            // cout << input;
            p[input - 1].a[ii] = j;
            p[input - 1].v     = input;
        }
        // cout << ii << endl;
    }
    // cout << "done" << endl;
    sort(p, p + n);
    for (int i = 0; i < n; i++) cout << p[i].v << " ";
}

