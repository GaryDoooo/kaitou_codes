#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, d[112345], fa[112345], q[112345];
set<int> e[112345];
void fill_to_root(vector<int>& a, int x) {
    do {
        a.push_back(x);
        x = fa[x];
    } while (x);
}

int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        e[a].insert(b);
        e[b].insert(a);
    }
    for (int i = 1; i <= n; i++) {
        if (d[i]) continue;
        int head = 1, tail = 1;
        q[tail] = i;
        d[i]    = 1;
        while (head <= tail) {
            int now = q[head++];
            // cout << now << endl;
            int depth = d[now] + 1;
            for (int i : e[now]) {
                if (d[i]) {
                    // cout << i << endl;
                    vector<int> left, right(1, i);
                    fill_to_root(left, i);
                    fill_to_root(right, now);
                    // cout << left.size() << " " << right.size() << endl;
                    // for (int i : right) cout << i << endl;
                    int joint_right, joint_left;
                    for (int i = left.size() - 1, j = right.size() - 1;;
                         j--, i--)
                        if (left[i] == right[j]) {
                            joint_right = j;
                            joint_left  = i;
                        } else
                            break;
                    printf("%d\n", joint_left + joint_right + 1);
                    for (int i = 0; i < joint_left; i++) printf("%d ", left[i]);
                    for (int i = joint_right; i >= 0; i--)
                        printf("%d ", right[i]);
                    return 0;
                } else {
                    q[++tail] = i;
                    d[i]      = depth;
                    fa[i]     = now;
                    e[i].erase(now);
                }
            }
        }
    }
    // for (int i = 1; i <= n; i++) printf("%d ", 2 - (d[i] & 1));
    puts("IMPOSSIBLE");
    return 0;
}
