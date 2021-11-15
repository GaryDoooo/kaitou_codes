#include <bits/stdc++.h>
#define W 9
using namespace std;
int d[] = {1, -1, W, -W}, a[100];
string s;
int res;
map<char, int> c2d = {{'U', 3}, {'D', 2}, {'R', 0}, {'L', 1}};
void dfs(int step, int pos) {
    if (pos == 64 and step < 49) return;
    if (step == 49) {
        res += (pos == 64);
        return;
    }
    int available[4];
    for (int i = 0; i < 4; i++) available[i] = a[pos + d[i]];
    if (available[1] and available[0]) {
        if (!available[2] and !available[3]) return;
    }
    if (available[2] and available[3]) {
        if (!available[0] and !available[1]) return;
    }
    char c = s[step - 1];
    if (c == '?') {
        for (int i = 0; i < 4; i++) {
            if (available[i]) {
                a[pos + d[i]] = 0;
                dfs(step + 1, pos + d[i]);
                a[pos + d[i]] = 1;
            }
        }
    } else {
        int i = c2d[c];
        if (available[i]) {
            a[pos + d[i]] = 0;
            dfs(step + 1, pos + d[i]);
            a[pos + d[i]] = 1;
        }
    }
}
int main() {
    cin >> s;
    for (int y = 1; y <= 7; y++) {
        for (int x = 1; x <= 7; x++) {
            a[y * W + x] = 1;
        }
    }
    a[10] = 0;
    dfs(1, 10);
    cout << res;
}
