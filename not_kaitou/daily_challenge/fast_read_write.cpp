#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#define int long long
#define rep(i,a,n) for(register int i=a;i<=n;i++)
#define dep(i,n,a) for(register int i=n;i>=a;i--)
using namespace std;
int l, n, m, d[100050];
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-')f = -1; ch = getchar();}
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x * f;
}
void write(int x) {
    if (x < 0)putchar('-'), x = -x;
    if (x == 0)return;
    write(x / 10);
    putchar('0' + x % 10);
}
bool check(int len) {
    int now = 0;
    int cnt = 0;
    rep(i, 1, n - 1) {
        if (d[i] - now >= len)now = d[i];
        else ++cnt;
        if (cnt > m)return false;
    }
    if (d[n] - now < len)++cnt;
    if (cnt > m)return false;
    return true;
}
signed main() {
    l = read(), n = read(), m = read();
    rep(i, 1, n)d[i] = read();
    d[n + 1] = l;
    ++n;
    int ll = 1, rr = l;
    while (ll < rr - 1) {
        int mid = (ll + rr) >> 1;
        if (check(mid))ll = mid;
        else rr = mid;
    }
    int ans;
    if (check(rr))ans = rr;
    else if (check(ll))ans = ll;
    write(ans);
    return 0;
}