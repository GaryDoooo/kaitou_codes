#include <stdio.h>
#include <algorithm>
using namespace std;
struct edge {
    int apple_on_this;
    int apple_on_this_and_sons;
    int node1, node2;
    int son_edge_count;
};
edge e[105];
int n, done[105], q,v[105];  //,node2,node1,apple;
// int res[105][105]; // res[a][b]

edge count_apple(int node) {
    // if (done[node]) return;
    edge res;
    res.apple_on_this_and_sons = 0;
    res.son_edge_count         = 0;
    done[node]                 = 1;
    int edges[2], edge_count = 0, sons[2];
    for (int i = 0; i < n - 1; i++) {
        if (e[i].node1 == node and done[e[i].node2] == 0) {
            edges[edge_count]  = i;
            sons[edge_count++] = e[i].node2;
        }
        if (e[i].node2 == node and done[e[i].node1] == 0) {
            edges[edge_count]  = i;
            sons[edge_count++] = e[i].node1;
        }
    }
    for (int i = 0; i < edge_count; i++) {
        edge temp                  = count_apple(sons[i]);
        e[edges[i]].son_edge_count = temp.son_edge_count;
        e[edges[i]].apple_on_this_and_sons =
            temp.apple_on_this_and_sons + e[edges[i]].apple_on_this;
        res.son_edge_count += temp.son_edge_count + 1;
        res.apple_on_this_and_sons += e[edges[i]].apple_on_this_and_sons;
    }
    return res;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &e[i].node1, &e[i].node2, &e[i].apple_on_this);
    }
    count_apple(1);
    
    // printf("%d\n", e[0].apple_on_this_and_sons);
    // sort(e, e + n, [](edge a, edge b) -> bool {
    //     return a.apple_on_this_and_sons > b.apple_on_this_and_sons;
    // });
    // for (int i = 0; i < n - 1; i++) {
    //     printf("%d %d\n", e[i].apple_on_this_and_sons, e[i].son_edge_count);
    // }
}
