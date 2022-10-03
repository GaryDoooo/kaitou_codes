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
int n;
ll calc(int p, int a[]) {
    ll res = 0;
    for (int i = 0; i < n; i++) res += abs(a[i] - p);
    return res;
}
int main() {
    n = read();
    int a[n], left = MAX_INT, right = MIN_INT;
    for (int i = 0; i < n; i++) {
        a[i]  = read();
        left  = min(left, a[i]);
        right = max(right, a[i]);
    }
    while (left < right) {
        int mid = (left + right) / 2;
        if (calc(mid, a) < calc(mid + 1, a))
            right = mid;
        else
            left = mid + 1;
    }
    cout << calc(left, a) << endl;
}
