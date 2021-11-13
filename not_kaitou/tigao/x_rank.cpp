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
    struct scores {
        int score, index;
        bool operator<(scores const& o) const { return score > o.score; }
    };
    int n = read();
    scores s[n];
    for (int i = 0; i < n; i++) {
        s[i] = {read(), i};
    }
    sort(s, s + n);
    int last = -1, last_res, res[n];
    for (int i = 0; i < n; i++) {
        if (s[i].score == last) {
            res[s[i].index] = last_res;
        } else {
            last     = s[i].score;
            last_res = res[s[i].index] = i + 1;
        }
    }
    for (int i = 0; i < n; i++) write(res[i]);
}
