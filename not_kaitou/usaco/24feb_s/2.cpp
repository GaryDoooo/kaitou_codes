#include <bits/stdc++.h>
using namespace std;

vector<int> from, to;
vector<int> a[3];

// int get_other(int a, int b) {
//     int c[3] = {1, 1, 1};
//     c[a] = c[b] = 0;
//     for (int i = 0; i < 3; i++) {
//         if (c[i]) return i;
//     }
// }
//
void pour(int u, int v) {
    int c = a[u].back();
    a[u].pop_back();
    if (a[v].size() == 0)
        a[v].push_back(c);
    else if (a[v].back() != c)
        a[v].push_back(c);
    from.push_back(u);
    to.push_back(v);
}

void work(int u, int v) {
    if (a[u].size() == 1)
        pour(v, u);
    else if (a[v].size() == 1)
        pour(u, v);
    else if (a[u].size() > a[v].size())
        pour(u, v);
    else
        pour(v, u);
}

void work0() {
    int t0;
    for (int i = 0; i < 3; i++)
        if (a[i].size() == 0) t0 = i;
    int pick = 0, m = 1e9;
    for (int i = 0; i < 3; i++)
        if (i != t0 and a[i].size() > 0) pick = i;
    for (int i = 0; i < 3; i++) {
        if (i == t0) continue;
        if (a[i].size() < m and a[i].size() > 1) {
            m    = a[i].size();
            pick = i;
        }
    }
    pour(pick, t0);
}

int check(int u, int v) {
    if (a[u].size() == 0 or a[v].size() == 0) return 0;
    return a[u].back() == a[v].back();
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, p;
        scanf("%d %d", &n, &p);
        for (int i = 0; i < 3; i++) a[i].clear();
        for (int i = 0; i < 2; i++) {
            char s[112345];
            scanf("%s\n", s);
            for (int j = 0; j < n; j++) {
                char c = s[j];
                int v  = 0;
                if (c == '1')
                    v = 1;
                else
                    v = 2;
                if (a[i].size() == 0)
                    a[i].push_back(v);
                else if (a[i].back() != v)
                    a[i].push_back(v);
            }
        }
        // cout << a[0].size() << endl;
        // cout << a[1].size() << endl;
        from.clear();
        to.clear();
        while (1) {
            if (a[0].size() + a[1].size() + a[2].size() == 2) {
                bool found = false;
                for (int i = 0; i < 3; i++)
                    if (a[i].size() > 1) found = true;
                if (!found) break;
            }
            if (check(0, 1))
                work(0, 1);
            else if (check(1, 2))
                work(1, 2);
            else if (check(0, 2))
                work(0, 2);
            else
                work0();
        }
        if (a[2].size() > 0)
            if (a[0].size() == 0)
                pour(2, 0);
            else
                pour(2, 1);
        printf("%lld\n", from.size());
        if (p > 1)
            for (int i = 0; i < from.size(); i++)
                printf("%d %d\n", from[i] + 1, to[i] + 1);
    }
}

