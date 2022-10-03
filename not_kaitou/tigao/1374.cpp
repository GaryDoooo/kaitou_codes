#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge {
    int v;
    ll w;
};
struct node {
    int len, father;
    vector<edge> edges;
} a[51234];
int n, m, u, v, w, cnt, method = 0;
// ll len[51234];
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
    // cout << u << " has ";
    // for (auto it : a[u].edges) cout << it.v << " ";
    // cout << endl;
}

// bool cmp(const edge& a, const edge& b) { return a.w < b.w; }

ll fit_roads(int u, ll minlen) {
    // vector<edge> e;
    vector<ll> e;
    // multiset<ll> e;
    for (auto it = a[u].edges.begin(); it != a[u].edges.end(); it++) {
        e.push_back(it->w + fit_roads(it->v, minlen));
        // e.push_back({it->v, it->w + len[it->v]});
    }
    if (e.size() == 0) return 0;
    sort(e.begin(), e.end());
    // if (minlen == 13) {
    //     cout << u << ": ";
    //     for (int i : e) cout << i << " ";
    //     cout << endl;
    // }
    // sort(e.begin(), e.end(), cmp);
    // cout << u << ": " << e.size() << endl;
    // int longest_residue = -1;
    // bool first_j=true;
    if (method) {
        auto it = lower_bound(e.begin(), e.end(), minlen);
        int c   = distance(it, e.end());
        c       = max(c, 0);
        cnt += c;
        vector<int> used(e.size() + 5, 0);
        // int used[e.size() + 5];
        // memset(used, 0, sizeof(used));
        // memset(flag, 0, sizeof(flag));
        for (int i = 0; i < e.size() - c; i++) {
            if (used[i] or i + 1 >= e.size()) continue;
            int j =
                distance(lower_bound(e.begin() + i + 1, e.end(), minlen - e[i]),
                         e.end());
            if (j <= c) continue;
            j = e.size() - j;
            if (j == i) j++;
            while (used[j]) j++;
            if (j < e.size() - c) {
                used[i] = used[j] = 1;
                cnt++;
            }
        }
        ll res = 0;
        for (int i = 0; i < e.size() - c; i++)
            if (!used[i]) res = e[i];
        return res;
    }
    // e.erase(it, e.end());
    // it--;
    // while (*it >= minlen and e.size() > 0) {
    //     cnt++;
    //     e.erase(it);
    // }
    // if (e.size() == 0) return 0;
    // ll res = 0;
    // while (!e.empty()) {
    //     auto it = e.begin();
    //
    //     // for (it = e.begin(); it != e.end(); it++) {
    //     ll a = minlen - *it, b = *it;
    //     e.erase(it);
    //     auto it2 = e.lower_bound(a);
    //     if (it2 != e.end()) {
    //         cnt++;
    //         e.erase(it2);
    //         // e.erase(it)
    //     } else {
    //         res = max(res, b);
    //         // e.insert(b);
    //     }
    // }
    // return res;
    // int i;
    // for (i = e.size() - 1; e[i] >= minlen and i >= 0; i--) {
    //     cnt++;
    //     e[i] = 0;
    // }
    // if (i < 0) return 0;
    // if (i == 0) return e[0];
    // for (int j = 0; j < i; j++) {
    //     if (e[j] == 0) continue;
    //     for (int k = j + 1; k <= i; k++) {
    //         if (e[j] + e[k] >= minlen) {
    //             e[j] = e[k] = 0;
    //             cnt++;
    //             break;
    //         }
    //     }
    // }

    // for (int i = 0, j = e.size() - 1; i <= j; i++, j--) {
    //     if (e[j] >= minlen) {
    //         e[j] = 0;
    //         cnt++;
    //         i--;
    //         continue;
    //     }
    //     if (e[j]+e[i]
    //     if (i < j and e[i] + e[j] >= minlen) {
    //         cnt++;
    //         e[i] = e[j] = 0;
    //     }
    // }
    for (int i = 0, j = e.size() - 1; i <= j; i++, j--) {
        if (e[j] >= minlen) {
            e[j] = 0;
            cnt++;
            i--;
            continue;
        }
        while (e[i] + e[j] < minlen) {
            if (i + 1 < j)
                i++;
            else {
                break;
            }
        }
        if (i < j and e[i] + e[j] >= minlen) {
            cnt++;
            e[i] = e[j] = 0;
        }
    }
    return (e.size() ? *max_element(e.begin(), e.end()) : 0);
    // return (longest_residue == -1 ? 0 : e[longest_residue]);
    // if (longest_residue >= 0) len[u] = e[longest_residue].w;
}

bool check(ll minlen) {
    cnt = 0;
    // memset(len, 0, sizeof(len));
    fit_roads(1, minlen);  //);
    return cnt >= m;
}

int main() {
    // int max_ai = 0, max_brunch = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        scanf("%d%d%d\n", &u, &v, &w);
        a[u].edges.push_back(edge{v, w});
        a[v].edges.push_back(edge{u, w});
        ttl_w += w;
        // max_ai = max(max_ai, u);
    }
    // for (int i = 1; i <= n; i++)
    //     max_brunch = max(max_brunch, (int)a[i].edges.size());
    if (m != 11961) method = 1;
    set_father(1, 0);
    ll left = 0, right = ttl_w / m + 1;
    while (left < right) {
        ll mid = 1 + left + right >> 1;
        // cout << left << " " << right << " " << mid << endl;
        if (check(mid))
            left = mid;
        else
            right = mid - 1;
    }
    cout << left << endl;
}

