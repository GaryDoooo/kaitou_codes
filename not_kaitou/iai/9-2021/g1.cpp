#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MIN_INT -2147483648
using namespace std;
typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unordered_set<int> usint;
inline int read() {
    int xxxxx = 0, fffff = 1;
    char ccccch = getchar();
    while (!isdigit(ccccch)) {
        if (ccccch == '-') fffff = -1;
        ccccch = getchar();
    }
    while (isdigit(ccccch)) {
        xxxxx  = (xxxxx << 1) + (xxxxx << 3) + (ccccch ^ 48);
        ccccch = getchar();
    }
    return xxxxx * fffff;
}
////////////////////////
int n, k, fixed_color[100001];
ull mod = 1e9 + 7;
vint son[100001];
ull times(ull a, ull b) {
    if (a == 0 or b == 0) return 0;
    ull x = (a * b) % mod;
    return (x == 0 ? mod : x);
}
struct choices {
    int choices_at_color[3] = {0};
};
choices paint(int node) {
    // cout << "start paint node " << node << endl;
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
    n = read(), k = read();
    memset(fixed_color, 255, sizeof(fixed_color));
    for (int i = 2; i <= n; i++) son[read()].push_back(i);
    for (int i = 1; i <= k; i++) {
        int node = read(), color = read();
        fixed_color[node] = color;
    }
    choices res = paint(1);
    ull result  = 0;
    for (int i = 0; i < 3; i++) result += res.choices_at_color[i];
    cout << result % mod;
}
