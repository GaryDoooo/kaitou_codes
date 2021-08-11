#include <bits/stdc++.h>
#define OVER_MAX 1300000001
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-')f = -1; ch = getchar();}
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x * f;
}
struct gap {
    int index, gap;
};
struct CompareLength {
    bool operator()(gap const &a, gap const &b) {
        return a.gap > b.gap;
    }
};
int main() {
    priority_queue<gap, vector<gap>, CompareLength> queue;
    int L, n, m, index, left, right;
    gap temp;
    cin >> L >> n >> m;
    int d[50005], l[50005], r[50005], g[n + 2];
    d[0] = 0; //d[n + 1] = L;
    for (int i = 1; i <= n; i++) {
        d[i] = read();
        l[i] = i - 1;
        r[i] = i + 1;
        g[i] = d[i] - d[i - 1];
        temp.index = i; temp.gap = g[i];
        queue.push(temp);
    }
    g[n + 1] = L - d[n]; temp.gap = g[n + 1]; temp.index = n + 1; queue.push(temp);
    g[0] = OVER_MAX; //temp.gap = g[0]; temp.index = 0; queue.push(temp);
    l[n + 1] = n;
    r[n + 1] = 0;
    l[0] = 0;
    for (int i = 0; i < m; i++) {
        temp = queue.top(); queue.pop();
        while (g[temp.index] != temp.gap) {
            if (g[temp.index] < OVER_MAX) temp.gap = g[temp.index], queue.push(temp);
            temp = queue.top(); queue.pop();
        }
        index = temp.index;
        left = l[index], right = r[index];
        if (g[left] < g[right]) {
            g[left] += g[index];
        } else {
            g[right] += g[index];
        }
        l[right] = left;
        r[left] = right;
        g[index] = OVER_MAX;
        // for (int j = 0; j < n + 2; j++) if (g[j] == OVER_MAX) cout << "- ";
        //     else {cout << g[j] << " ";}
        // cout << endl;
        // vector<pair<int, int>> buffer;
        // while (!queue.empty()) {
        //     buffer.push_back(make_pair(queue.top().index, queue.top().gap));
        //     printf("%d~%d~%d ", queue.top().index, queue.top().gap, g[queue.top().index]);
        //     queue.pop();
        // }
        // for (auto i : buffer) {
        //     temp.index = i.first; temp.gap = i.second;
        //     queue.push(temp);
        // }
        // cout << endl << queue.size() << endl; //>>
    }
    cout << min(*min_element(g, g + n + 2), L) << endl;
    int dis = 0;
    for (int i = 1; i <= n + 1; i++) {if (g[i] < OVER_MAX) dis += g[i], cout << dis << " "; }
    return 0;
}