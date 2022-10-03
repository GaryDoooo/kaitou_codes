#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, done[112345], head = 1, tail;
typedef pair<int, int> pii;
pii q[112345];
vector<int> edges[112345];
int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    q[++tail] = {n, 0};
    done[n]   = 1;
    while (head <= tail) {
        int now = q[head].first;
        for (int i : edges[now]) {
            if (i == 1) {
                // for (int i = 0; i < 10; i++)
                //     cout << q[i].first << " " << q[i].second << endl;
                vector<int> path(1, 1);
                do {
                    path.push_back(q[head].first);
                    head = q[head].second;
                } while (head);
                printf("%d\n", path.size());
                for (int i : path) printf("%d ", i);
                return 0;
            }
            if (!done[i]) {
                done[i]   = 1;
                q[++tail] = {i, head};
            }
        }
        head++;
    }
    puts("IMPOSSIBLE");
}

