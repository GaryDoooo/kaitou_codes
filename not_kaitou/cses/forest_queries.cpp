#include <bits/stdc++.h>
#include <algorithm>
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
int n, q;
int s[1005][1005];

int main() {
    n = read();
    q = read();
    for (int y = 1; y <= n; y++)
        for (int x = 1; x <= n; x++) {
            char c;
            do {
                c = getchar();
                // putchar(c);
            } while (c != '.' && c != '*');
            s[x][y] = (c == '*') + s[x - 1][y] + s[x][y - 1] - s[x - 1][y - 1];
            // cout << x << " " << y << endl;
        }
    while (q--) {
        int y1   = read();
        int x1   = read();
        int y2   = read();
        int x2   = read();
        int ymax = max(y1, y2);
        int ymin = min(y1, y2);
        int xmin = min(x1, x2);
        int xmax = max(x1, x2);
        write(s[xmax][ymax] - s[xmin - 1][ymax] - s[xmax][ymin - 1] +
              s[xmin - 1][ymin - 1]);
    }
}
