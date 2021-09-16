#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-')f = -1; ch = getchar();}
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x * f;
}
struct item {
    int p, q, in = 0;
};
bool cmp(item const &a, item const &b) { return a.q < b.q;}
bool cmp2(item const &a, item const &b) {return a.p < b.p;}
int main() {
    int n = read(), k = read();
    long long m = read();
    item it[n];
    for (int i = 0; i < n; i++) it[i].p = read(), it[i].q = read();
    sort(it, it + n, cmp);
    long long used_m = 0, cnt = 0;
    for (int i = 0; i < k; i++) {
        used_m += it[i].q; cnt++; it[i].in = 1;
        if (used_m > m) {
            cout << cnt - 1;
            return 0;
        }
    }
    sort(it, it + n, cmp2);
    for (int i = 0; i < n; i++) {
        if (it[i].in) continue;
        used_m += it[i].p; cnt++;
        if (used_m > m) {
            cout << cnt - 1;
            return 0;
        }
    }
    cout << n;
}