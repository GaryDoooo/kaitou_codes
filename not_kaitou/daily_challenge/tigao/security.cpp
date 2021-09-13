#include <bits/stdc++.h>
using namespace std;
int l, n, cnt = 0;
char c[26], res[15];
void output() {
    char buf[l];
    bool has_aieou = false;
    for (int i = 0; i < l; i++) {
        buf[i] = res[i];
        if (buf[i] == 'a' or buf[i] == 'e' or buf[i] == 'i' or buf[i] == 'o' or buf[i] == 'u') has_aieou = true;
    }
    buf[l] = 0;
    if (has_aieou) {
        if (++cnt > 25000) exit(0);
        // printf("%s\n", buf);
        cout << buf << endl;
    }
}
void dfs(int c_i, int r_i) {
    if (r_i == l) {output(); return;}
    if (c_i >= n) return;
    for (int i = c_i; i < n; i++) {
        res[r_i] = c[i];
        dfs(i + 1, r_i + 1);
    }
}
int main() {
    cin >> l >> n;
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(c, c + n);
    dfs(0, 0);
}