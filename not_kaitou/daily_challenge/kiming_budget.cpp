#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x * f;
}
int main() {
    int maxw = read() / 10, n = read();
    int w[n + 1], v[n + 1], father;
    int bestv[maxw + 1];
    vector<int> new_w, new_v;
    vector<int> son_nodes[n + 1];
    memset(bestv, 0, sizeof(bestv));
    for (int i = 1; i <= n; i++) {
        w[i] = read() / 10, v[i] = read() * w[i], father = read();
        if (father) {son_nodes[father].push_back(i); son_nodes[i].push_back(-1);}
    }
    for (int i = 1; i <= n; i++) {
        if (son_nodes[i].size() == 0) {
            new_w.push_back(w[i]); new_v.push_back(v[i]);
        } else if (son_nodes[i].size() == 1) {
            if (son_nodes[i][0] > 0) {
                new_w.push_back(w[i]); new_v.push_back(v[i]);
                new_w.push_back(w[i] + w[son_nodes[i][0]]);
                new_v.push_back(v[i] + v[son_nodes[i][0]]);
            }
        } else if (son_nodes[i].size() == 2) {
            new_w.push_back(w[i]); new_v.push_back(v[i]);
            new_w.push_back(w[i] + w[son_nodes[i][0]]);
            new_v.push_back(v[i] + v[son_nodes[i][0]]);
            new_w.push_back(w[i] + w[son_nodes[i][1]]);
            new_v.push_back(v[i] + v[son_nodes[i][1]]);
            new_w.push_back(w[i] + w[son_nodes[i][0]] + w[son_nodes[i][1]]);
            new_v.push_back(v[i] + v[son_nodes[i][0]] + w[son_nodes[i][1]]);
        }
    }
    for (int i = 0; i < new_w.size(); i++) {
        for (int j = maxw; j >= new_w[i]; j--) {
            bestv[j] = max(bestv[j], bestv[j - new_w[i]] + new_v[i]);
        }
    }
    cout << *max_element(bestv, bestv + maxw + 1) * 10;
}