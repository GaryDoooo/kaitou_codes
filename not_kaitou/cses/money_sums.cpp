#include <bits/stdc++.h>
using namespace std;
bitset<112345> s;
int n, x, sum, ans[112345], ttl;
int main() {
    scanf("%d", &n);
    s[0] = 1;
    while (n--) {
        scanf("%d", &x);
        s = (s << x) | s;
        // s<<=x;
        sum += x;
    }
    for (int i = 1; i <= sum; i++) {
        // s >>= 1;
        if (s[i]) ans[ttl++] = i;
    }
    printf("%d\n", ttl);
    for (int i = 0; i < ttl; i++) printf("%d ", ans[i]);
    puts("");
}

