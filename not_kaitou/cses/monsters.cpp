#include <bits/stdc++.h>
using namespace std;
char inp[1005], *direction = "UDLR";
int m[1005][1005], w, h, res;
int start_x, start_y, end_x, end_y, head = 1, tail;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
struct node {
    int steps, x, y, in_direction, father, is_monster;
};
node q[1123456];
// vector<int> monster_x, monster_y;

int main() {
    cin >> h >> w;
    for (int y = 1; y <= h; y++) {
        scanf("%s\n", inp);
        // cout << inp << endl;
        for (int x = 0; x < w; x++) {
            // cout << inp[x] << endl;
            m[x + 1][y] = inp[x] == '.';
            if (inp[x] == 'A') start_x = x + 1, start_y = y;
            if (inp[x] == 'M') q[++tail] = {0, x + 1, y, 0, 0, 1};
            // monster_x.push_back(x + 1), monster_y.push_back(y);
        }
    }
    // for (int i=0; i < monster_x.size(); i++){
    //     q[++tail]={0,monster_x[i],monster_y[i],
    q[++tail] = {0, start_x, start_y, 0, 0, 0};
    while (head <= tail) {
        node n = q[head];
        for (int i = 0; i < 4; i++) {
            int nx = n.x + dx[i], ny = n.y + dy[i];
            if ((nx < 1 or ny < 1 or nx > w or ny > h) and n.is_monster == 0) {
                cout << "YES" << endl;
                cout << n.steps << endl;
                // cout << n.path + direction[i] << endl;
                int res[n.steps + 1], idx = n.steps;
                res[idx] = i;
                int i    = head;
                while (i) {
                    res[--idx] = q[i].in_direction;
                    i          = q[i].father;
                }
                for (int i = 0; i < n.steps; i++) putchar(direction[res[i]]);
                putchar('\n');
                return 0;
            }
            if (m[nx][ny]) {
                m[nx][ny] = 0;
                q[++tail] = {n.steps + 1, nx, ny, i, head, n.is_monster};
                // q.push({n.steps + 1, nx, ny, n.path + direction[i]});
            }
        }
        head++;
    }
    cout << "NO" << endl;
}
