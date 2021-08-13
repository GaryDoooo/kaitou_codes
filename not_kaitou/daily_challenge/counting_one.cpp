#include <bits/stdc++.h>
using namespace std;
inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
    char ch = nc(); int x = 0; // int flag = 1;
    while (!(ch >= '0' && ch <= '9')) ch = nc();
    while (ch >= '0' && ch <= '9')x = (x << 1) + (x << 3) + (ch ^ 48), ch = nc();
    return x;
}

int count_one(int a) {
    int ones[7] = {0, 1, 20, 300, 4000, 50000, 600000};
    int right = a / 10, d = a % 10, left = 0, sum = 0, digits = 0;
    while (d > 0) {
        left = d * 10 + left;
        d = right % 10;
        right /= 10;
        digits++;
    }
    return sum;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n = read(), a, b;
    // cin >> n;
    cout << count_one(n) << endl;
    // for (int i = 0; i < n; i++) {
    //     // cin >> a >> b;
    //     a = read(); b = read();
    //     cout << count_one(b) - count_one(a - 1) << endl;
    // }
}