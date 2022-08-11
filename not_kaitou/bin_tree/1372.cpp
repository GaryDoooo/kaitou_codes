#include <bits/stdc++.h>
using namespace std;
struct node {
    int d, v, l, r;
    int side;
};
struct chain {
    int lf_head = 0, lf_tail = 0;
    int rf_head = 0, rf_tail = 0;
    int total_nodes = 0;
};
node a[5000005];
int lFirst[5000005], rFirst[5000005];
int n, res = 1;
int void_node_index = 1e6 + 5;
chain chain_zero;
void set_depth(int node_index, int depth, int side) {
    a[node_index].d    = depth;
    a[node_index].side = side;
    a[node_index].v += depth * 1001;
    if (a[node_index].l > 0) set_depth(a[node_index].l, depth + 1, 0);
    if (a[node_index].r > 0) set_depth(a[node_index].r, depth + 1, 1);
}

chain test_tree(int node_index) {
    chain result, res_l = chain_zero, res_r = chain_zero;
    if (a[node_index].l <= 0 and a[node_index].r <= 0) {
        result.lf_head = result.rf_head = result.lf_tail = result.rf_tail =
            node_index;
        result.total_nodes = node_index <= 1e6;
        return result;
    }
    if (a[node_index].l > 0) res_l = test_tree(a[node_index].l);
    if (a[node_index].r > 0) res_r = test_tree(a[node_index].r);
    result.total_nodes += 1 + res_l.total_nodes + res_r.total_nodes;
    if (res_l.total_nodes == res_r.total_nodes) {
        bool symetric = true;
        int left = res_l.lf_head, right = res_r.rf_head;
        while (1) {
            if (a[left].v != a[right].v or a[left].side == a[right].side) {
                symetric = false;
                break;
            }
            if (left == res_l.lf_tail or right == res_r.rf_tail) {
                if (left == res_l.lf_tail and right == res_r.rf_tail) break;
                symetric = false;
                break;
            }
            left = lFirst[left], right = rFirst[right];
        }
        if (symetric) res = max(res, result.total_nodes);
    }
    result.lf_head = result.rf_head = node_index;
    // connect left first chain
    lFirst[node_index]    = res_l.lf_head;
    lFirst[res_l.lf_tail] = res_r.lf_head;
    result.lf_tail        = res_r.lf_tail;
    // connect right first chain
    rFirst[node_index]    = res_r.rf_head;
    rFirst[res_r.rf_tail] = res_l.rf_head;
    result.rf_tail        = res_l.rf_tail;
    return result;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].v);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].l, &a[i].r);
        if (a[i].l == -1 and a[i].r > 0) a[i].l = void_node_index++;
        if (a[i].r == -1 and a[i].l > 0) a[i].r = void_node_index++;
    }
    set_depth(1, 0, 0);
    test_tree(1);
    printf("%d\n", res);
}
