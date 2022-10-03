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
    int h = read(), w = read();
    string s;
    int a[h + 2][w + 2];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= h; i++) {
        cin >> s;
        for (int j = 0; j < w; j++) a[i][j + 1] = (int)s[j];
    }
    int res = 0;
    for (int y = 1; y <= h; y++) {
        for (int x = 1; x <= w; x++) {
            if (a[y][x] > 0) {
                struct xy {
                    int x, y;
                };
                vector<xy> todo;
                int left = 0, value = a[y][x];
                todo.push_back({x, y});
                a[y][x] = 0;
                while (todo.size() > left) {
                    xy now   = todo[left++];
                    int dx[] = {1, -1, 0, 0};
                    int dy[] = {0, 0, 1, -1};
                    for (int i = 0; i < 4; i++) {
                        int nx = now.x + dx[i], ny = now.y + dy[i];
                        if (a[ny][nx] == value) {
                            todo.push_back({nx, ny});
                            a[ny][nx] = 0;
                        }
                    }
                }
                res = max(res, (int)todo.size());
                todo.clear();
            }
        }
    }
    cout << res << endl;
}
