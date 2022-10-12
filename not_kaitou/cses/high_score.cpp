#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> pii;
#define to first
#define val second
struct node {
    ll score = -1e14;
    vector<pii> sons;
    bitset<2505> fa;
} a[2505];
int n, m, x, y, z, in_q[2505];
queue<int> q;
int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &x, &y, &z);
        a[x].sons.push_back({y, z});
    }
    a[1].score = 0;
    q.push(1);
    in_q[1] = 1;
    while (q.size()) {
        int e = q.front();  // q[head++];
        q.pop();
        in_q[e] = 0;
        for (auto i : a[e].sons) {
            // a[i.to].fa.insert(e);
            // a[i.to].fa.insert(a[e].fa.begin(), a[e].fa.end());
            a[i.to].fa[e] = true;
            a[i.to].fa |= a[e].fa;
            if (a[i.to].score >= 1e18) continue;
            ll new_score = min(a[e].score + (ll)i.val, (ll)1e18);
            if (new_score > a[i.to].score) {
                // if (a[e].fa.find(i.to) != a[e].fa.end())
                if (a[e].fa[i.to] == true)
                    a[i.to].score = 1e18;
                else
                    a[i.to].score = max(a[i.to].score, new_score);
                if (!in_q[i.to]) {
                    in_q[i.to] = 1;
                    q.push(i.to);
                }
            }
        }
    }
    if (a[n].score <= -1e14)
        cout << 0 << endl;
    else if (a[n].score >= 1e18)
        cout << -1 << endl;
    else
        cout << a[n].score << endl;
}

