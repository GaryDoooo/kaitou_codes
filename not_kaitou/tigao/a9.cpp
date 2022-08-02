#include <bits/stdc++.h>
using namespace std;
struct node {
    int a, b, x, delta_y;
};
struct cmp {
    bool operator()(const node& a, const node& b) {
        return a.delta_y < b.delta_y;
    }
};
// bool operator<(const node& a, const node& b) { return a.delta_y > b.delta_y;
priority_queue<node, vector<node>, cmp> q;
int n, k, a, b;
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) { scanf("%d%d", &a, &b); if (a <= b) continue; node t = {.a = a, .b = b, .x = 0, .delta_y = a - b}; // q.insert(t);
        q.push(t);
    }
    int dx                 = 0;
    unsigned long long res = 0;
    // for (auto i : q) cout << i.delta_y << endl;
    while (dx < k and q.size() > 0) {
        // res += q.begin()->delta_y;
        res += q.top().delta_y;
        // cout << res << endl;
        dx++;
        // int x = q.begin()->x, a = q.begin()->a, b = q.begin()->b;
        int x = q.top().x + 1, a = q.top().a, b = q.top().b; q.pop();
        // q.erase(q.begin());
        int next_dy =
            ((x + 1) * a - b * (x + 1) * (x + 1)) - (a * x - b * x * x); if (next_dy <= 0) continue; node t = {.a = a, .b = b, .x = x, .delta_y = next_dy}; // q.insert(t);
        q.push(t);
    }
    cout << res << endl;
}
