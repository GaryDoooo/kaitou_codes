#include <bits/stdc++.h>
using namespace std;
inline __int128 read() {
    __int128 x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        x = x * 10 + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
int main() {
    __int128 a = read(), b = read();
    a -= b;
    if (a < 0) putchar('-'), a = -a;
    if (a == 0) {
        cout << 0;
        return 0;
    }
    string s = "";
    int cnt  = 0;
    while (a > 0) {
        int i = a % 10;
        s.insert(0, 1, '0' + i);
        a /= 10;
        if (++cnt == 3 and a > 0) s = "," + s, cnt = 0;
    }
    cout << s;
}

