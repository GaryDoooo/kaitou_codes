#include <bits/stdc++.h>
// #define start first
// #define len second
using namespace std;
int n, m, s, e, a[200005], closest[200005], head = 1, tail;
map<int, int> last_occurrence;

struct node2 {
    int start, len;
};
// pair<int, int>
node2 q[200005], f[200005][20];

// bool operator<(pair<int, int> const &aa, pair<int, int> const &bb) {
//     return aa.len < bb.len;
// }
bool operator<(node2 const &aa, node2 const &bb) { return aa.len < bb.len; }

struct node {
    int start, len;
};
struct compare {
public:
    bool operator()(node const &a, node const &b) { return a.start > b.start; }
};
priority_queue<node, vector<node>, compare> qt2;

// pair<int, int>
node2 find_max(int s, int e) {
    // if (s == e) return {s, 1};
    int k = trunc(log2(e - s + 1));
    return max(f[s][k], f[e + 1 - (1 << k)][k]);
}

node2 make_pair(int a1, int a2) {
    node2 res = {a1, a2};
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        if (last_occurrence[a[i]]) {
            closest[last_occurrence[a[i]]] = i;
        }
        last_occurrence[a[i]] = i;
    }

    // for (int i = 1; i <= n; i++) cout << closest[i] << " ";
    // cout << endl;
    // int head = 1, tail = 0;
    for (int i = 1; i <= n; i++) {
        // cout << head << " " << tail << endl;
        // cout << "queue:" << i << " ";
        // for (int j = head; j <= tail; j++)
        //     cout << q[j].start << "," << q[j].len << " ";
        // cout << endl;
        while (head <= tail and q[head].start + q[head].len <= i) {
            int ts = q[head].start, tl = q[head].len;
            f[q[head].start][0] = make_pair(q[head].start, q[head].len);
            head++;
            while (!qt2.empty() and qt2.top().start < ts) {
                int x   = qt2.top().start;
                f[x][0] = make_pair(x, i - x);
                // cout << x << " " << i << endl;
                qt2.pop();
            }
        }
        if (closest[i] == 0) closest[i] = n + 1;
        while (head <= tail and q[tail].start + q[tail].len >= closest[i]) {
            // f[q[tail].start][0] =
            // qt[++tail2] =
            // qt2.push(make_pair(q[tail].start, closest[i] - q[tail].start));
            qt2.push({q[tail].start, closest[i] - q[tail].start});
            tail--;
        }
        q[++tail] = make_pair(i, closest[i] - i);
    }
    while (!qt2.empty()) {
        int x   = qt2.top().start;
        f[x][0] = make_pair(x, n - x + 1);
        qt2.pop();
    }
    f[n][0] = make_pair(n, 1);
    // for (int i = 1; i <= n; i++) cout << f[i][0].len << endl;
    // cout << endl;
    /////////////////////////////////////
    //
    for (int k = 1, j = 1; k <= n; k <<= 1, j++) {
        for (int i = 0; i + k < n; i++) {
            f[i][j] = max(f[i][j - 1], f[i + k][j - 1]);
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << i << " " << a[i] << ": ";
    //     for (int j = 0; j < 7; j++) cout << f[i][j].len << " ";
    //     cout << endl;
    // }
    // cin >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &s, &e);
        // cin >> s >> e;
        int right = e, res, res2 = 0;
        node2 found;
        // pair<int, int> found;
        do {
            res   = res2;
            found = find_max(s, right);
            res2  = min(found.len, e - found.start + 1);
            right = found.start - 1;
            if (right < s) {
                res = max(res, res2);
                break;
            }
            // cout << "res=" << res << " res2=" << res2 << endl;
        } while (res2 > res);
        printf("%d\n", (res == 0 ? res2 : res));
    }
}
