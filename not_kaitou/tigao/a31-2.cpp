#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
struct edge {
    int node1, node2, apple;
};
edge e[105];
struct node {
    int apple;
    vector<int> children;
};
node a[105];
bool done[105];
int res[105][105], max_cut[105], n, q;

void travel(int node_index) {
    if (done[node_index]) return;
    done[node_index] = true;
    // vector<int> edges,sons;
    for (int i = 1; i < n; i++) {
        if (e[i].node1 == node_index and !done[e[i].node2]) {
            // edges.push_back(i); sons.push_back(e[i].node2);
            a[node_index].children.push_back(e[i].node2);
            a[e[i].node2].apple = e[i].apple;
            travel(e[i].node2);
        }
        if (e[i].node2 == node_index and !done[e[i].node1]) {
            // edges.push_back(i); sons.push_back(e[i].node1);
            a[node_index].children.push_back(e[i].node1);
            a[e[i].node1].apple = e[i].apple;
            travel(e[i].node1);
        }
    }
}

void process(int node_index) {
    if (a[node_index].children.size() == 0) {
        res[node_index][1]  = a[node_index].apple;
        max_cut[node_index] = 1;
        return;
    }
    int left = a[node_index].children[0], right = a[node_index].children[1];
    process(left);
    process(right);
    for (int i = 0; i <= max_cut[left]; i++) {
        for (int j = 0; j <= max_cut[right]; j++) {
            if (res[left][i] < 1e9 and res[right][j] < 1e9) {
                res[node_index][i + j] =
                    min(res[node_index][i + j], res[right][j] + res[left][i]);
            }
        }
    }
    max_cut[node_index]                  = max_cut[right] + max_cut[left] + 1;
    res[node_index][max_cut[node_index]] = a[node_index].apple +
                                           res[left][max_cut[left]] +
                                           res[right][max_cut[right]];
}

int main() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        cin >> e[i].node1 >> e[i].node2 >> e[i].apple;
    }
    memset(res, 127, sizeof(res));
    for (int i = 1; i <= n; i++) res[i][0] = 0;
    a[1].apple = 0;
    travel(1);
    process(1);
    cout << res[1][n - 1] - res[1][n - 1 - q] << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ":" << a[i].apple << " ";
    //     for (auto j : a[i].children) cout << j << " ";
    //     cout << endl;
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= max_cut[i]; j++) {
    //         cout << res[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

