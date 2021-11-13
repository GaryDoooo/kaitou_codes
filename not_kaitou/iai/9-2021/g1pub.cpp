#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

struct choices {
    int choices_at_color[3] = {0};
};
int n, k, fixed_color[100001], in1, in2;
ull mod = 1e9 + 7;
vector<int> son[100001];

ull times(ull a, ull b) {
    if (a == 0 or b == 0) return 0;
    ull x = (a * b) % mod;
    return (x == 0 ? mod : x);
}

choices paint(int node) {
    choices res;
    vector<choices> paint_res;
    for (int son_node : son[node]) paint_res.push_back(paint(son_node));
    for (int i = 0; i < 3; i++) {
        if (fixed_color[node] >= 0 and i != fixed_color[node]) continue;
        ull choice_cnt = 1;
        for (choices choice_of_node : paint_res) {
            ull node_choice_cnt = 0;
            for (int j = 0; j < 3; j++)
                if (i != j)
                    node_choice_cnt += choice_of_node.choices_at_color[j];
            choice_cnt = times(choice_cnt, node_choice_cnt);
        }
        res.choices_at_color[i] = choice_cnt;
    }
    return res;
}

int main() {
    cin >> n >> k;
    memset(fixed_color, 255, sizeof(fixed_color));
    for (int i = 2; i <= n; i++) cin >> in1, son[in1].push_back(i);
    for (int i = 1; i <= k; i++) {
        cin >> in1 >> in2;
        fixed_color[in1] = in2;
    }
    choices res = paint(1);
    ull result  = 0;
    for (int i = 0; i < 3; i++) result += res.choices_at_color[i];
    cout << result % mod;
}
