#include <bits/stdc++.h>
#define INF 2123456789
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
int main() {
    int n = read(), k = read();
    int v[n + 1];
    long long res = 0;
    v[n] = INF;
    for (int i = 0; i < n; i++) v[i] = read();
    sort(v, v + n);
    int right_pointer = upper_bound(v, v + n, v[0] + k) - v - 1;
    for (int i = 0; i < n; i++) {
        while (v[right_pointer] < v[i] + k) right_pointer++;
        if (right_pointer == n)break;
        res += n - right_pointer;
    }
    cout << res << endl;
    return 0;
}
