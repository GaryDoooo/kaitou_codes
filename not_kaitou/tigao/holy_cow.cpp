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
int n, b, d;
int m[256][256], pick[20];
bool dfs(int i, int from) {
    if (i >= n) return true;
    for (int j = from; j < (1 << b); j++) {
        bool good = true;
        for (int k = 0; k < i; k++)
            if (m[pick[k]][j] < d) good = false;
        if (good) {
            pick[i] = j;
            if (dfs(i + 1, j + 1)) return true;
        }
    }
    return false;
}
int main() {
    n = read(), b = read(), d = read();
    for (int i = 0; i < 256; i++)
        for (int j = 0; j < i; j++) {
            int diff = (i ^ j), cnt = 0;
            while (diff > 0) {
                cnt += diff & 1;
                diff >>= 1;
            }
            m[j][i] = m[i][j] = cnt;
        }
    dfs(0, 0);
    for (int i = 0; i < n; i++) cout << pick[i] << " ";
}
