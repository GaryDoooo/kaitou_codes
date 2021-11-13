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
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48);  // 48 是 '0'
    // putchar(' ');
}
////////////////////////
int W = 102;
struct status {
    int spending, pos, color, casted;
    bool operator<(const status& other) const {
        return spending < other.spending;
    }
};
int main() {
    int a[W * W], now_best[W * W], endpos;
    memset(now_best, 120, sizeof(now_best));
    memset(a, 255, sizeof(a));
    int m = read(), n = read();
    if (m == 1) {
        cout << 0;
        return 0;
    }
    for (int y = 1; y <= m; y++)
        for (int x = 1; x <= m; x++) a[y * W + x] = 0;
    for (int i = 0; i < n; i++) {
        int x = read(), y = read();
        a[y * W + x] = read() + 1;
    }
    endpos = m * W + m;
    multiset<status> stages;
    stages.insert({0, W + 1, a[W + 1], 0});
    now_best[W + 1] = 0;
    int res         = MAX_INT;
    int d[]         = {1, -1, W, -W};
    while (!stages.empty()) {
        status now = *stages.begin();
        stages.erase(stages.begin());
        // cout << now.pos << endl;
        if (now.spending >= res) break;
        for (int i : d) {
            status next;
            next.pos = now.pos + i;
            if (a[next.pos] < 0) continue;
            if (a[next.pos] == 0) {
                if (now.casted) continue;
                next.casted   = 1;
                next.spending = 2 + now.spending;
                next.color    = now.color;
                if (next.pos == endpos) {
                    res = min(res, next.spending);
                    continue;
                }
                if (next.spending >= now_best[next.pos] + 1) continue;
                now_best[next.pos] = min(now_best[next.pos], next.spending);
                stages.insert(next);
            } else {
                next.casted   = 0;
                next.spending = (a[next.pos] != now.color) + now.spending;
                if (next.pos == endpos) {
                    res = min(res, next.spending);
                    continue;
                }
                next.color = a[next.pos];
                if (next.spending >= now_best[next.pos]) continue;
                now_best[next.pos] = next.spending;
                stages.insert(next);
            }
        }
    }
    if (res < MAX_INT)
        write(res);
    else
        write(-1);
}
