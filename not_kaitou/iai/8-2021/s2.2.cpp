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
int main() {
    priority_queue<int, vector<int>, greater<int>> right;  // is smallest on top
    priority_queue<int, vector<int>, less<int>> left;      // is largest on top
    int n = read();
    int a[3];
    for (int i = 0; i < 3; i++) a[i] = read();
    printf("%d\n", a[0]);
    sort(a, a + 3);
    left.push(a[0]);
    right.push(a[2]);
    int mid = a[1];
    printf("%d\n", mid);
    for (int i = 3; i < n; i += 2) {
        int a1 = read(), a2 = read();
        if (a1 <= mid and a2 >= mid) {
            left.push(a1);
            right.push(a2);
        } else if (a2 <= mid and a1 >= mid) {

            left.push(a2);
            right.push(a1);
        } else if (a1 >= mid) {
            left.push(mid);
            right.push(a1);
            right.push(a2);
            mid = right.top();
            right.pop();
        } else {
            right.push(mid);
            left.push(a1);
            left.push(a2);
            mid = left.top();
            left.pop();
        }
        printf("%d\n", mid);
    }
}

