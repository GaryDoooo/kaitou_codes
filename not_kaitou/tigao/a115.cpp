#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int n, root, most_connected, max_connections, A, b, l, done[112345];
ll res = 2e18;
struct node {
    int father, c, depth;
    vector<int> connections;
    vector<int> len;
    ll all_sons_d, family_wo_me_d, all_sons_c, family_wo_me_c;
};
node a[112345];

void dfs(int idx, int depth, int father) {
    a[idx].depth  = depth;
    a[idx].father = father;
    for (int son : a[idx].connections) {
        if (son == father) continue;
        dfs(son, depth + 1, idx);
    }
    ll all_sons_d = 0, all_sons_c = 0;
    for (int i = 0; i < a[idx].len.size(); i++) {
        if (a[idx].connections[i] == father) continue;
        int son = a[idx].connections[i];
        all_sons_c += a[son].c + a[son].all_sons_c;
        all_sons_d +=
            a[son].all_sons_d + (a[son].c + a[son].all_sons_c) * a[idx].len[i];
    }
    a[idx].all_sons_c = all_sons_c;
    a[idx].all_sons_d = all_sons_d;
    for (int i = 0; i < a[idx].len.size(); i++) {
        if (a[idx].connections[i] == father) continue;
        int son = a[idx].connections[i];
        a[son].family_wo_me_c =
            a[idx].c + a[idx].all_sons_c - a[son].all_sons_c - a[son].c;
        a[son].family_wo_me_d = a[son].family_wo_me_c * a[idx].len[i] +
                                all_sons_d - a[son].all_sons_d -
                                (a[son].c + a[son].all_sons_c) * a[idx].len[i];
    }
}

void find_res(int idx, int father, ll acc_d, ll acc_c) {
    // cout << idx << " " << acc_d << " " << acc_c << endl;
    res = min(res, acc_d + a[idx].all_sons_d);
    for (int i = 0; i < a[idx].len.size(); i++) {
        int son = a[idx].connections[i];
        if (son == father) continue;
        find_res(son, idx,
                 acc_d + (acc_c)*a[idx].len[i] + a[son].family_wo_me_d,
                 acc_c + a[son].family_wo_me_c);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d\n", &a[i].c);
    for (int i = 1; i < n; i++) {
        scanf("%d%d%d\n", &A, &b, &l);
        a[A].connections.push_back(b);
        a[b].connections.push_back(A);
        a[A].len.push_back(l);
        a[b].len.push_back(l);
    }
    for (int i = 1; i <= n; i++)
        if (a[i].connections.size() > max_connections) {
            max_connections = a[i].connections.size();
            most_connected  = i;
        }
    root = most_connected;
    dfs(root, 0, root);
    find_res(root, root, 0, 0);
    cout << res << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << a[i].c << " " << a[i].all_sons_d << " " << a[i].all_sons_c
    //          << " " << a[i].family_wo_me_c << " " << a[i].family_wo_me_d
    //          << endl;
    // cout << root << endl;
}
