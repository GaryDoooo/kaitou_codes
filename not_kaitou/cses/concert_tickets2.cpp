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
    int n = read(), m = read();
    vector<int> in(n);
    for (int i = 0; i < n; i++) in[i] = read();
    sort(in.begin(), in.end());
    // multiset<int> p;
    // auto it = p.begin();
    // for (auto vit = in.begin(); vit != in.end(); ++vit) it = p.insert(it,
    // *vit);
    multiset<int> p(in.begin(), in.end());
    for (int i = 0; i < m; i++) {
        int a   = read();
        auto it = p.lower_bound(a);
        if (it == p.end()) {
            if (it == p.begin()) {
                putchar('-');
                putchar('1');
                putchar(' ');
                continue;
            }
            it--;
        }
        if (*it > a) {
            if (it == p.begin()) {
                putchar('-');
                putchar('1');
                putchar(' ');
                // printf("-1 ");
                continue;
            }
            it--;
        }
        write(*it);
        p.erase(it);
    }
}
