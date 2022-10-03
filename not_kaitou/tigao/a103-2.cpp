#include <stdio.h>
#include <set>
using namespace std;
struct Node {
    int pressure, depth, father;
    set<int> children;
};

Node a[50005];
int n, k, done[50005], node1, node2, res;

void travel(int node, int depth, int father) {
    a[node].depth  = depth;
    a[node].father = father;
    a[node].children.erase(father);
    for (int child : a[node].children) travel(child, depth + 1, node);
}

void set_change(int start, int end) {
    if (a[start].depth > a[end].depth) swap(start, end);
    int same_depth_node_from_end   = end;
    int same_depth_node_from_start = start;
    a[end].pressure++;
    while (a[same_depth_node_from_end].depth >
           a[same_depth_node_from_start].depth) {
        same_depth_node_from_end = a[same_depth_node_from_end].father;
        a[same_depth_node_from_end].pressure++;
    }
    if (same_depth_node_from_end == start) {
        // a[start].in++;
        return;
    }
    a[start].pressure++;
    while (same_depth_node_from_end != same_depth_node_from_start) {
        same_depth_node_from_start = a[same_depth_node_from_start].father;
        a[same_depth_node_from_start].pressure++;
        same_depth_node_from_end = a[same_depth_node_from_end].father;
        a[same_depth_node_from_end].pressure++;
    }
    // a[start].out++;
    a[same_depth_node_from_end].pressure--;
}

void find_max_by_travel(int node) {
    res = max(res, a[node].pressure);  // + a[node].in);
    // int new_pressure = pressure - a[node].out + a[node].in;
    for (int child : a[node].children)
        find_max_by_travel(child);  //, new_pressure);
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &node1, &node2);
        a[node1].children.insert(node2);
        a[node2].children.insert(node1);
    }
    travel(1, 0, 1);  // Set 1 as root
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &node1, &node2);
        set_change(node1, node2);
    }
    find_max_by_travel(1);
    printf("%d\n", res);
    // for (int i = 1; i <= n; i++) {
    //     printf("node:%d d:%d f:%d in:%d out:%d ", i, a[i].depth, a[i].father,
    //            a[i].in, a[i].out);
    //     for (int child : a[i].children) printf("%d ", child);
    //     puts("\n");
    // }
}
