#include <bits/stdc++.h>
using namespace std;
struct range {
    int l, r, includes, included, idx;
} a[212345];
int n, l, r;
bool operator<(const range& a, const range& b) {
    return a.r > b.r and a.l == b.l or a.l < b.l;
}
bool cmp(const range& a, const range& b) { return a.idx < b.idx; }
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l, &r);
        a[i] = {l, r, 0, 0, i};
    }
    sort(a, a + n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        a[i].included = (m >= a[i].r);
        m             = max(m, a[i].r);
    }
    m = 2e9;
    for (int i = n - 1; i >= 0; i--) {
        a[i].includes = (m <= a[i].r);
        m             = min(m, a[i].r);
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) printf("%d ", a[i].includes);
    puts("");
    for (int i = 0; i < n; i++) printf("%d ", a[i].included);
}
