#include <bits/stdc++.h>
using namespace std;
struct edge {
    int u, v;        // u->v
    int start_node;  // node #, if 0 the edge is availalbe
    int fa;          // prev step, first step's fa is 0;
    int step_num;    // count step on this path
    int ee_i;  // index of edge on node u, for continue to try untried edges;
               // need test if to try all edges or untried ones;
};
edge e[1005];
vector<int> path_start;  // node # of the nodes 1 step from "1" starting points
int path_tail[505];      // pointer to the step chain idx node #
int n, m;
vector<int> ee[505];  // edge idx from one node idx is node #
int vis_e_cur[1005];  // if the edge is visisted in this round
int start_node_order[505];
// int vis_node_cur_path[505];  // if the node is visited in this path before

void mark_new_path(int prev_edge) {
    path_tail[e[prev_edge].start_node] = prev_edge;
    int start_node                     = e[prev_edge].start_node;
    for (int i = 1; i <= m; i++)
        if (e[i].start_node == start_node)
            e[i].start_node = 0, vis_e_cur[i] = 0;
    // clean all the old marks
    for (int i = prev_edge; i; vis_e_cur[i] = 1, i = e[i].fa)
        e[i].start_node = start_node;  // trace the new path mark
}

int found_path(const int prev_edge, const int start_ee_i);

int trace_back(int edge_idx) {
    for (int ei = edge_idx; ei; ei = e[ei].fa)
        if (found_path(e[ei].fa,  // Go back one step at this old path
                       0
                       // e[ei].ee_i + 1  // start trying from the next edge on
                       // the node
                       ))
            return 1;
    return 0;
}

int found_path(const int prev_edge, const int start_ee_i) {
    if (e[prev_edge].v == n) {
        mark_new_path(prev_edge);
        return 1;
    }
    //
    int vis_node_cur_path[505], cur_node = e[prev_edge].v,
                                start_node = e[prev_edge].start_node;
    memset(vis_node_cur_path, 0, sizeof(vis_node_cur_path));
    for (int i = prev_edge; i; i = e[i].fa) vis_node_cur_path[e[i].v] = 1;
    vis_node_cur_path[1] =
        1;  // Get all the previous nodes on the path to prevent loops
            //
    queue<int> q;
    for (int i = start_ee_i; i < ee[cur_node].size(); i++)
        if (e[ee[cur_node][i]].start_node == 0) q.push(ee[cur_node][i]);

    for (int i = start_ee_i; i < ee[cur_node].size(); i++)
        if (e[ee[cur_node][i]].start_node > 0) q.push(ee[cur_node][i]);

    while (!q.empty()) {
        int ei = q.front();
        q.pop();
        if (vis_e_cur[ei]) continue;
        if (vis_node_cur_path[e[ei].v]) continue;
        if (start_node_order[e[ei].start_node] > start_node_order[start_node])
            continue;  // if the edge belongs to future paths
        vis_e_cur[ei] = 1;
        if (e[ei].start_node == start_node) {
            e[ei].fa = prev_edge;
            mark_new_path(path_tail[start_node]);  // the new path connected
                                                   // to old tails
            return 1;
        }
        // Here the e[ei]'s start node must less than current start node,
        // It's previous paths
        if (e[ei].start_node > 0) {  // The edge is not free, but on an old path
            // cout << "trace back " << e[ei].start_node << endl;
            if (!trace_back(ei)) continue;  //
        }
        // Up to here the edge is free to be added to current path
        e[ei].start_node = start_node;
        e[ei].fa         = prev_edge;
        if (found_path(ei, 0)) return 1;
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &e[i].u, &e[i].v);
        e[i].ee_i = ee[e[i].u].size();
        ee[e[i].u].push_back(i);
    }
    for (int i = 0; i < ee[1].size(); i++)
        path_start.push_back(e[ee[1][i]].v);  // all the nodes connected to 1
    int path_cnt = 0, order_cnt = 0;
    sort(path_start.begin(),
         path_start.end());  // only changes the paths smaller than current
    for (int start_node : path_start) {
        start_node_order[start_node] = ++order_cnt;
        // cout << start_node << endl;
        // memset(vis_node_cur_path, 0, sizeof(vis_node_cur_path));
        memset(vis_e_cur, 0, sizeof(vis_e_cur));
        int prev_edge = 0;
        for (int i : ee[1]) {
            if (e[i].v == start_node) prev_edge = i;
            // vis_node_cur_path[e[i].v] = 1;
            vis_e_cur[i] = 1;
        }
        // vis_node_cur_path[1]    = 1;
        e[prev_edge].start_node = start_node;
        e[prev_edge].step_num   = 1;
        path_cnt += found_path(prev_edge, 0);
    }
    printf("%d\n", path_cnt);
}

