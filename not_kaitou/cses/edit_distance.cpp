#include <bits/stdc++.h>
using namespace std;
string a, b;
int f[5005][5005], q[5005];
// int dis(int x, int y) {
//     if (y < 0) return x + 1;
//     if (x < 0) return y + 1;
//     if (f[x][y] >= 0) return f[x][y];
//     int res = 1e9;
//     for (int i = y; i >= 0; i--) {
//         if (res <= y - i) break;
//         if (a[x] == b[i])
//             res = min(res, dis(x - 1, i - 1) + y - i);
//         else
//             res = min(min(res, dis(x - 1, i - 1) + y - i + 1),
//                       dis(x - 1, i) + y - i + 1);
//     }
//     return f[x][y] = res;
// }
// struct fxy {
//     int y, fxy;
// };
// bool operator<(fxy const& a, fxy const& b) { return a.fxy - a.y > b.fxy -
// b.y; }
int main() {
    cin >> a >> b;
    int res = 1e9;
    memset(f, 127, sizeof(f));
    // for (int i = 0; i < b.size(); i++)
    //     res = min(res, dis((int)a.size() - 1, i) + (int)b.size() - 1 - i);
    for (int i = 0; i < 5003; i++) f[0][i] = f[i][0] = i;
    int bs = b.size(), as = a.size();
    for (int x = 1; x <= as; x++) {
        int head = 1, tail = 1;
        q[tail] = 0;
        // priority_queue<fxy, vector<fxy>, less<fxy>> q;
        // q.push({0, f[x][0]});
        for (int y = 1; y <= bs; y++) {
            if (f[x][y] <= bs - y) break;
            if (a[x - 1] == b[y - 1])
                f[x][y] = min(f[x][y], f[x - 1][y - 1]);  // + bs - y);
            //.size()); dis(x - 1, i - 1) + y - i);
            else
                f[x][y] =
                    min(f[x][y], min(f[x - 1][y - 1] + 1,  // + bs - y + 1,
                                     f[x - 1][y] + 1));    // + bs - y + 1));
            // res = min(min(res, dis(x - 1, i - 1) + y - i + 1),
            //           dis(x - 1, i) + y - i + 1);
            // f[x][y] = min(f[x][y], q.top().fxy + y - q.top().y);
            f[x][y] = min(f[x][y], f[x][q[head]] + y - q[head]);
            // q.push({y, f[x][y]});
            while (head <= tail and f[x][y] - y < f[x][q[tail]] - q[tail])
                tail--;
            q[++tail] = y;
        }
    }
    for (int y = 0; y <= bs; y++) res = min(res, f[as][y] + bs - y);
    cout << res << endl;
}
