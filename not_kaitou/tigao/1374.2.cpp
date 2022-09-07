#include <bits/stdc++.h>
using namespace std;
typedef int ll;
struct edge {
    int v;
    ll w;
};
struct node {
    int len, father;
    vector<edge> edges;
} a[51234];
int n, m, u, v, w, cnt;
ll ttl_w;

void set_father(int u, int fa) {
    auto fa_it  = a[u].edges.end();
    a[u].father = fa;
    for (auto it = a[u].edges.begin(); it != a[u].edges.end(); ++it) {
        if (it->v == fa) {
            fa_it = it;
        } else {
            set_father(it->v, u);
        }
    }
    if (fa_it != a[u].edges.end()) a[u].edges.erase(fa_it);
}

ll fit_roads(int u, ll minlen) {
    multiset<int> e;  //<ll> e;
    for (auto it = a[u].edges.begin(); it != a[u].edges.end(); it++) {
        int t = it->w + fit_roads(it->v, minlen);
        if (t >= minlen)
            cnt++;
        else
            e.insert(t);
    }
    int res = 0;
    while (!e.empty()) {
        auto it = e.begin();
        ll a = minlen - *it, b = *it;
        e.erase(it);
        auto it2 = e.lower_bound(a);
        if (it2 != e.end()) {
            cnt++;
            e.erase(it2);
        } else
            res = max(res, b);
    }
    return res;
}

bool check(ll minlen) {
    cnt = 0;
    fit_roads(1, minlen);  //);
    return cnt >= m;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        scanf("%d%d%d\n", &u, &v, &w);
        a[u].edges.push_back(edge{v, w});
        a[v].edges.push_back(edge{u, w});
        ttl_w += w;
    }
    set_father(1, 0);
    ll left = 0, right = ttl_w / m + 1;
    while (left < right) {
        ll mid = 1 + left + right >> 1;
        if (check(mid))
            left = mid;
        else
            right = mid - 1;
    }
    cout << left << endl;
}
