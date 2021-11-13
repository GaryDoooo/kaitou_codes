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
int a[1005][1005], done[1005][1005];
void fill(int x, int y) {
    struct point {
        int x, y;
    };
    vector<point> todo;
    int left   = 0;
    done[y][x] = 1;
    todo.push_back({x, y});
    while (left < todo.size()) {
        int xx = todo[left].x, yy = todo[left++].y;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i], ny = yy + dy[i];
            if (done[ny][nx]) continue;
            if (a[ny][nx] != (a[yy][xx] ^ 1)) continue;
            todo.push_back({nx, ny});
            done[ny][nx] = 1;
        }
    }
    for (auto p : todo) a[p.y][p.x] = todo.size();
}

int main() {
    int n = read(), m = read();
    string s;
    memset(a, 255, sizeof(a));
    memset(done, 0, sizeof(done));
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) a[i][j + 1] = (s[j] == '1');
    }
    for (int y = 1; y <= n; y++)
        for (int x = 1; x <= n; x++) {
            if (done[y][x]) continue;
            fill(x, y);
        }
    for (int i = 0; i < m; i++) {
        int y = read(), x = read();
        cout << a[y][x] << endl;
    }
}
