#include <bits/stdc++.h>
using namespace std;
int m[55][55], n, done[55], dist;
char c1, c2;
struct node {
    int dist, end;
};
bool operator<(const node& a, const node& b) { return a.dist < b.dist; }
multiset<node> q;
int to_index(char c) { return (c <= 'Z' ? c - 'A' : c - 'a' + 26); }
int main() {
    scanf("%d\n", &n);
    memset(m, 127, sizeof(m));
    for (int i = 0; i < n; i++) {
        scanf("%c %c %d\n", &c1, &c2, &dist);
        int n1 = to_index(c1), n2 = to_index(c2);
        m[n1][n2] = min(m[n1][n2], dist);
        m[n2][n1] = min(m[n2][n1], dist);
    }
    q.insert({0, 25});
    while (!q.empty()) {
        node now      = *q.begin();
        done[now.end] = 1;
        q.erase(q.begin());
        if (now.end < 25) {
            cout << char('A' + now.end) << " " << now.dist << endl;
            return 0;
        }
        for (int next = 0; next < 52; next++) {
            if (done[next] or m[now.end][next] > 2e9) continue;
            q.insert({m[now.end][next] + now.dist, next});
        }
    }
}
