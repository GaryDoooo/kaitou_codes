#include <bits/stdc++.h>
using namespace std;
int a[592345], h, w, x, y, done[592345], res;
int seq[592345];
bool cmp(int x, int y) { return a[x] > a[y]; }
int main() {
    cin >> h >> w;
    int W   = w + 2;
    int d[] = {-W - 1, -W, -W + 1, -1, 1, W - 1, W, W + 1};
    memset(a, 128, sizeof(a));
    for (int y = 1; y <= h; y++)
        for (int x = 1; x <= w; x++) {
            int index = y * W + x;
            cin >> a[index];
            seq[index] = index;
        }
    sort(seq, seq + W * (h + 2), cmp);
    for (int i = 0; i < W * h; i++) {
        int idx = seq[i];
        if (done[idx] or a[idx] <= 0) continue;
        res++;
        stack<int> s;
        s.push(idx);
        done[idx] = 1;
        while (!s.empty()) {
            int now = s.top();
            s.pop();
            for (int j = 0; j < 8; j++) {
                int nw = now + d[j];
                if (a[nw] <= a[now] and a[nw] >= 0 and done[nw] == 0) {
                    // hill_top.erase(nw);
                    s.push(nw);
                    done[nw] = 1;
                }
            }
        }
    }
    cout << res << endl;
}

// for (int i = 1; i <= W * h; i++) {
//     if (a[i] < 0) continue;
//     int max_neighbor = a[i];
//     for (int j = 0; j < 8; j++)
//         max_neighbor = max(max_neighbor, a[i + d[j]]);
//     if (max_neighbor > a[i]) continue;
//     bool found = false;
//     for (int j = 0; j < 8; j++) {
//         auto it = hill_top.find(i + d[j]);
//         if (it != hill_top.end()) found = true;
//     }
//     if (!found) hill_top.insert(i);
// }
// for (int i : hill_top) cout << i / W << " " << i % W << endl;
// set<int> t(hill_top.begin(), hill_top.end());
// for (int start : t) {
//     // if (done[start]) continue;
//     memset(done, 0, sizeof(done));
// }
// cout << hill_top.size() << endl;
// for (int i : hill_top) cout << i / W << " " << i % W << endl;
