#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x  = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x;
}
int main() {
    int n = read(), m       = read();
    long long s[n + 1], sum = 0;
    for (int i = 1; i <= n; i++) s[i] = sum = sum + read();
    long long cnt = 0;
    s[0]          = 0;
    for (int i = 1; i <= n; i++) {
        long long compare = (long long)i * m;
        for (int j = 0; j <= n - i; j++) {
            cnt += (s[j + i] - s[j] >= compare);
        }
    }
    cout << cnt << endl;
}
