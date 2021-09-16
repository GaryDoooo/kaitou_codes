#include <bits/stdc++.h>
using namespace std;
int res = 0, n, masks[15];
bool OK(long long x, int len) {
    if (len < 3) return true;
    for (int check_length = 1; check_length <= len / 3; ++check_length) {
        register long long temp = x >> (len - check_length * 3);
        register int mask = masks[check_length];
        unsigned int a1 = temp & mask, a2 = (temp >> check_length)&mask, a3 = (temp >> check_length) >> check_length;
        if (a1 == a2 and a3 == a2) return false;
    }
    return true;
}
void dfs(long long x, int index) {
    if (index >= n) res++;
    else {
        if (OK(x, index + 1)) dfs(x, index + 1);
        x |= (1LL << index);
        if (OK(x, index + 1)) dfs(x, index + 1);
    }
}
int main() {
    for (int i = 1; i < 15; ++i) masks[i] = (1 << i) - 1;
    cin >> n;
    dfs(0LL, 0);
    cout << res;
}