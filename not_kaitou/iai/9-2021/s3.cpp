#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x  = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
bool working(int m, int t[], int n, int T) {
    // cout << m << endl;
    priority_queue<int> counters;
    int idx = 0;
    for (int i = 0; i < m; i++) {
        if (t[idx] > T) return false;
        counters.push(-t[idx++]);
    }
    for (int j = idx; j < n; j++) {
        int temp = counters.top() - t[j];
        if (temp < -T) return false;
        counters.pop();
        counters.push(temp);
    }
    // while (!counters.empty()) {
    //     cout << counters.top() << " ";
    //     counters.pop();
    // }
    // cout << endl;
    return true;
}
int main() {
    int n = read();
    int t[n];
    for (int i = 0; i < n; i++) t[i] = read();
    int T    = read();
    int left = 1, right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (working(mid, t, n, T)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left;
}
