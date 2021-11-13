#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MIN_INT -2147483648
using namespace std;
typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unordered_set<int> usint;
inline int read() {
    int xxxxx = 0, fffff = 1;
    char ccccch = getchar();
    while (!isdigit(ccccch)) {
        if (ccccch == '-') fffff = -1;
        ccccch = getchar();
    }
    while (isdigit(ccccch)) {
        xxxxx  = (xxxxx << 1) + (xxxxx << 3) + (ccccch ^ 48);
        ccccch = getchar();
    }
    return xxxxx * fffff;
}
inline void write(int x) {
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48);  // 48 是 '0'
    putchar(' ');
}
////////////////////////

int main() {
    int n = read(), res = 0;
    vector<vector<int>> f(n);
    for (int i = 0; i < n; i++) {
        int a = read(), line = 0;
        while (true) {
            // if (line == f.size()) {
            //     vector<int> t{a};
            //     f.push_back(t);
            //     break;
            // }
            auto it = upper_bound(f[line].begin(), f[line].end(), a);
            if (it == f[line].end()) {
                f[line].push_back(a);
                break;
            }
            swap(*it, a);
            res = max(res, ++line);
        }
        // cout << i << endl;
    }
    cout << res + 1;
}
