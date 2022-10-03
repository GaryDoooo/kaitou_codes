#include <bits/stdc++.h>
using namespace std;
int f[305][305], n, m, in_q[301], done[301];  //,father,credit;
// f[i,j] use i node as root, pick j classes max credit
struct node {
    int credit = 0, father = 0;
    vector<int> sons;
};
node c[301];
queue<int> q;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &c[i].father, &c[i].credit);
        c[c[i].father].sons.push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (c[i].sons.size() == 0) q.push(i);
        // for (int i = 1; i <= n; i++)
        // if (c[i].father == 0) c[0].sons.push_back(i);
    }
    // for (int i : c[0].sons) cout << i << " ";
    // cout << endl;
    c[0].credit = 1;
    while (q.size()) {
        int i = q.front();
        q.pop();
        bool all_done = true;
        for (int son : c[i].sons)
            if (!done[son]) {
                all_done = false;
                break;
            }
        if (!all_done) {
            q.push(i);
            continue;
        }
        // cout << i << " " << c[i].sons.size() << endl;
        if (!in_q[c[i].father]) {
            q.push(c[i].father);
            in_q[c[i].father] = 1;
        }
        f[i][1] = c[i].credit;
        for (int son : c[i].sons) {
            int t[305];
            // if (i == 0) cout << son << endl;
            memcpy(t, f[i], sizeof(t));
            for (int j = 1; f[son][j]; j++) {
                for (int k = 1; f[i][k]; k++) {
                    if (k + j > m + 1) break;
                    t[k + j] = max(t[k + j], f[i][k] + f[son][j]);
                }
            }
            // for (int j = 0; j <= m + 1; j++) cout << t[j] << " ";
            // cout << endl;
            memcpy(f[i], t, sizeof(t));
        }
        done[i] = 1;
    }
    // for (int i = 0; i <= n; i++) {
    //     cout << i << ": ";
    //     for (int j = 0; j <= m + 1; j++) cout << f[i][j] << " ";
    //     cout << endl;
    // }
    printf("%d\n", f[0][min(m, n) + 1] - 1);
}

