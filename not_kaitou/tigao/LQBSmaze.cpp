#include <bits/stdc++.h>
using namespace std;
int main() {
    int h, w;
    scanf("%d %d\n", &h, &w);
    int a[h][w];
    map<char, int> m = {{'L', 0}, {'Q', 1}, {'B', 2}, {'S', 3}};
    string s;
    // cout << w << " " << h << endl;
    for (int y = 0; y < h; y++) {
        cin >> s;
        // cout << s;
        for (int x = 0; x < w; x++) {
            a[y][x] = m[s[x]];
            // cout << s[x] << m[s[x]] << endl;
        }
    }
    // cout << endl;
    int done[h][w], res = 0;
    memset(done, 0, sizeof(done));
    for (int y0 = 0; y0 < h; y0++)
        for (int x0 = 0; x0 < w; x0++) {
            // cout << a[y0][x0];
            if (a[y0][x0] != 0 or done[y0][x0] != 0) continue;
            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};
            stack<int> todo_x, todo_y, count;
            todo_x.push(x0);
            todo_y.push(y0);
            count.push(0);
            done[y0][x0] = 1;
            while (!todo_y.empty()) {
                int x = todo_x.top(), y = todo_y.top(), cnt = count.top();
                todo_x.pop();
                todo_y.pop();
                count.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 or nx >= w or ny < 0 or ny >= h) continue;
                    if (a[ny][nx] != (a[y][x] + 1) % 4) continue;
                    if (done[ny][nx]) {
                        cout << -1;
                        return 0;
                    }
                    cnt += (a[ny][nx] == 3);
                    res = max(res, cnt);
                    todo_y.push(ny);
                    todo_x.push(nx);
                    count.push(cnt);
                    done[ny][nx] = 1;
                }
            }
        }
    cout << res;
}
