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
struct movie {
    int s, e;
    bool operator<(const movie& o) const { return e < o.e; }
};
int main() {
    int n = read();
    movie m[n];
    for (int i = 0; i < n; i++) m[i] = {read(), read()};
    sort(m, m + n);
    int s = 0, cnt = 0, i = 0;
    while (i < n) {
        if (m[i].s >= s) {
            s = m[i].e;
            cnt++;
        }
        i++;
    }
    write(cnt);
}
