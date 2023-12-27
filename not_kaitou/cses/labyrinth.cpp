#include <bits/stdc++.h>
using namespace std;
char inp[1005], *direction = "UDLR";
int m[1005][1005], w, h, res;
int start_x, start_y, end_x, end_y, head, tail;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
struct node {
    int steps, x, y, in_direction, father;
};
node q[1123456];

int main() {
    cin >> h >> w;
    for (int y = 1; y <= h; y++) {
        scanf("%s\n", inp);
        // cout << inp << endl;
        for (int x = 0; x < w; x++) {
            // cout << inp[x] << endl;
            m[x + 1][y] = inp[x] == '.';
            if (inp[x] == 'A') start_x = x + 1, start_y = y;
            if (inp[x] == 'B') end_x = x + 1, end_y = y;
        }
    }
    q[0] = {0, start_x, start_y, 0, 0};
    while (head <= tail) {
        node n = q[head];
        for (int i = 0; i < 4; i++) {
            int nx = n.x + dx[i], ny = n.y + dy[i];
            if (nx == end_x && ny == end_y) {
                cout << "YES" << endl;
                cout << n.steps + 1 << endl;
                // cout << n.path + direction[i] << endl;
                int res[n.steps + 1], idx = n.steps;
                res[idx] = i;
                int i    = head;
                while (i) {
                    res[--idx] = q[i].in_direction;
                    i          = q[i].father;
                }
                for (int i = 0; i <= n.steps; i++) putchar(direction[res[i]]);
                putchar('\n');
                return 0;
            }
            if (m[nx][ny]) {
                m[nx][ny] = 0;
                q[++tail] = {n.steps + 1, nx, ny, i, head};
                // q.push({n.steps + 1, nx, ny, n.path + direction[i]});
            }
        }
        head++;
    }
    cout << "NO" << endl;
}
