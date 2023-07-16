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
int t[812345], x[412345];

int main() {
    int n  = read();
    int n0 = (1 << (int)trunc(log2(n - 1)) + 1) - 1;
    // cout << n0 << endl;
    // This is same to n0 = (1 << ((sizeof(int) * CHAR_BIT) - __builtin_clz(n -
    // 1))) - 1;
    for (int i = 1; i <= n; i++) {
        x[i]      = read();
        t[n0 + i] = 1;
    }
    for (int i = n0; i > 0; i--) t[i] = t[i << 1] + t[i << 1 | 1];
    // make the binary tree
    while (n--) {
        int a = read();
        int k = 1, cnt = 0;
        // for (int i = 0; i < n0 * 2; i++) cout << t[i] << " ";
        // cout << endl;
        while (k <= n0) {
            int l = k << 1;
            int r = l | 1;
            if (t[l] + cnt >= a)  // take the left branch
                k = l;
            else {
                cnt += t[l];
                k = r;  // take the right branch, but count need include the
                        // total from left
            }
            // cout << k << endl;
        }
        // cout << k << endl;
        // here k>n0, it means k is on leaf nodes
        write(x[k - n0]);
        t[k] = 0;
        while ((k >>= 1) > 0) t[k] = t[k << 1] + t[k << 1 | 1];
    }
}
