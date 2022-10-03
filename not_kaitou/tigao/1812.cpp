#include <bits/stdc++.h>
#define ll __int128
using namespace std;
ll gcd2(ll x, ll y) { return (y ? gcd2(y, x % y) : x); }
ll gcd(ll x, ll y) { return (y > x ? gcd2(y, x) : gcd2(x, y)); }
struct frac {
    ll n, d = 1;
};
frac make_frac(ll n, ll d) {
    ll g = gcd(n, d);
    frac r;
    r.n = n / g;
    r.d = d / g;
    return r;
}
std::ostream& operator<<(std::ostream& dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char* d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}
frac operator+(frac const& a, frac const& b) {
    ll n = a.n * b.d + b.n * a.d, d = a.d * b.d;
    return make_frac(n, d);
}
frac operator/(frac const& a, frac const& b) {
    ll n = a.n * b.d, d = a.d * b.n;
    return make_frac(n, d);
}
struct node {
    frac v;
    int in;
    vector<int> out;
} a[112345];
int n, m, d, b;
vector<int> outlet_idx;
queue<int> q;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d);
        if (d == 0)
            outlet_idx.push_back(i);
        else {
            for (int j = 0; j < d; j++) {
                scanf("%d", &b);
                a[i].out.push_back(b);
                a[b].in++;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        q.push(i);
        a[i].v.n = 1;
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (a[now].out.empty()) continue;
        frac to_each_out = a[now].v / make_frac(a[now].out.size(), 1);
        for (ll dest : a[now].out) {
            a[dest].v = a[dest].v + to_each_out;
            if (--a[dest].in) continue;
            q.push(dest);
        }
    }
    for (int i : outlet_idx) cout << a[i].v.n << " " << a[i].v.d << endl;
    // printf("%lld %lld\n", (unsigned long long)a[i].v.n,
    // (unsigned long long)a[i].v.d);
    // frac a, b;
    // a.n = 1, a.d = 8;
    // b.n = 3, b.d = 8;
    // a = a / b;
    // cout << a.n << "/" << a.d << endl;
}
