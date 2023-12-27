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
    int n = read(), x = read();
    int a[n];
    for (int i = 0; i < n; i++) a[i] = read();
    multiset<int> s(a, a + n);
    int res = 0;
    while (!s.empty()) {
        // cout << s.size(
        // ) << endl;
        auto right = s.end();
        right--;
        auto left = s.upper_bound(x - *right);
        if (left != s.begin()) {
            left--;
            if (left == right and left != s.begin()) left--;
            if (left != right) s.erase(left);
        }
        s.erase(right);
        res++;
    }
    write(res);
}
