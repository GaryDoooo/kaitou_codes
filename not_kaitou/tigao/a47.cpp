#include <bits/stdc++.h>
using namespace std;
struct node {
    int father, depth;
    vector<int> connections;
    int ancestors[20];
    // vector<int> ancestors;
    // set<int> ancestors;
};
node tree[41234];
set<int> nds;
// int rec[41234][41234];
int root, n, t, a, b, done[41234], maxd;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d\n", &a, &b);
        if (b == -1)
            root = a;
        else {
            tree[a].connections.push_back(b);
            tree[b].connections.push_back(a);
            nds.insert(b);
            nds.insert(a);
        }
    }
    stack<int> s;
    s.push(root);
    done[root]              = 1;
    tree[root].ancestors[0] = root;
    while (!s.empty()) {
        int now = s.top();
        s.pop();
        for (int nxt : tree[now].connections) {
            if (done[nxt]) continue;
            tree[nxt].father       = now;
            tree[nxt].ancestors[0] = now;
            maxd      = max(maxd, tree[nxt].depth = tree[now].depth + 1);
            done[nxt] = 1;
            // tree[nxt].ancestors.insert(tree[now].ancestors.begin(),
            //                            tree[now].ancestors.end());
            // tree[nxt].ancestors.insert(now);
            s.push(nxt);
        }
    }
    for (int j = 1, k = 1; k < maxd; j++, k <<= 1)
        for (int i : nds)
            tree[i].ancestors[j] =
                tree[tree[i].ancestors[j - 1]].ancestors[j - 1];
    scanf("%d", &t);
    // cout << maxd << endl;
    while (t--) {
        scanf("%d%d\n", &a, &b);
        // cout << tree[a].depth << " " << tree[b].depth << endl;
        if (tree[a].depth == tree[b].depth)
            printf("0\n");
        else {
            int ans = 1;
            if (tree[a].depth > tree[b].depth) {
                swap(a, b);
                ans = 2;
            }
            while (tree[b].depth > tree[a].depth) {
                int k = trunc(log2(tree[b].depth - tree[a].depth));
                b     = tree[b].ancestors[k];
            }
            // auto it = tree[b].ancestors.find(a);
            // if (it != tree[b].ancestors.end())
            if (a == b)
                printf("%d\n", ans);
            else
                puts("0");
        }
    }
}
