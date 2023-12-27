#include <bits/stdc++.h>
#define BASE 100005
using namespace std;

int n, m, k[212345], visited[212345];
int q[212345], q_tail, k_first_in_queue[212345], k_last_in_queue[212345];
int edge[212345], nxt[212345], head[212345], e_cnt;
int res[212345], result[212345];
unordered_set<int> ke[212345];
int top_idx[212345], top_res[212345], top_cnt;
int in_cnt[212345];

int get_root(int x) {
    int xx = x;
    while (k[xx]) xx = k[xx];
    if (x != xx) k[x] = xx;
    return xx;
}

void combine_root(int a, int b) {
    int ar = get_root(a), br = get_root(b);
    if (ar == br) return;
    k[br] = k[b] = ar;
}

void dfs(int x) {
    visited[x]  = 1;
    q[++q_tail] = x;
    int xr      = get_root(x);
    if (k_first_in_queue[xr] == 0) k_first_in_queue[xr] = q_tail;
    k_last_in_queue[xr] = q_tail;
    for (int e = head[x]; e; e = nxt[e]) {
        int to = edge[e];
        if (visited[to]) {
            int to_r = get_root(to);
            if (to_r == xr) continue;
            if (k_first_in_queue[to_r]) {
                for (int i = k_last_in_queue[to_r] + 1; i <= q_tail; i++) {
                    combine_root(to_r, q[i]);
                }
            }
            k_last_in_queue[to_r] = q_tail;
        } else {
            dfs(to);
        }
    }
    xr = get_root(x);
    if (k_first_in_queue[xr] == q_tail)
        k_first_in_queue[xr] = k_last_in_queue[xr] = 0;
    else
        k_last_in_queue[xr]--;
    q_tail--;
}

void add_edge2(int a, int b) {
    edge[++e_cnt]  = b + BASE;
    nxt[e_cnt]     = head[a + BASE];
    head[a + BASE] = e_cnt;
}

void add_edge(int a, int b) {
    add_edge2(-a, b);  //, e2 =
    add_edge2(-b, a);
}

void convert_edge(int x) {
    int xr = res[x];
    for (int e = head[x]; e; e = nxt[e]) {
        int to_r = res[edge[e]];
        if (to_r == xr) continue;
        ke[xr].insert(to_r);
    }
}

void print_res() {
    for (int i = 1; i <= m; i++) {
        int root_yes = result[res[BASE + i]], root_no = result[res[BASE - i]];
        if (root_yes) {
            if (root_no) printf("ERROR topping %d\n", i);
            printf("+ ");
        } else {
            if (root_no == 0) printf("BOTH zero %d\n", i);
            printf("- ");
        }
    }
    exit(0);
    // puts("");
    // for (int i = 1; i <= m; i++)
    //     printf("topping %d: rYes=%d rNo=%d result Y%d N%d\n", i, res[BASE +
    //     i],
    //            res[BASE - i], result[res[BASE + i]], result[res[BASE - i]]);
}

int find_dfs(int topping);

int proceed(int topping, int root) {
    stack<int> to_change;
    to_change.push(root);
    stack<int> s;
    s.push(root);
    result[root] = 1;
    while (!s.empty()) {
        int x = s.top();
        s.pop();
        for (auto to : ke[x]) {
            if (result[to] == 0) {
                to_change.push(to);
                result[to] = 1;
                s.push(to);
            }
        }
    }
    int return_value = find_dfs(topping + 1);
    while (!to_change.empty()) {
        result[to_change.top()] = 0;
        to_change.pop();
    }
    return return_value;
}

int find_dfs(int topping) {
    if (topping > m) {
        print_res();
        return 1;
    }
    int root_yes = res[BASE + topping], root_no = res[BASE - topping];
    if (result[root_yes] == 1) {
        if (result[root_no] == 0) {
            return find_dfs(topping + 1);
        } else {
            return 0;
        }
    } else {
        if (result[root_no] == 1) {
            return find_dfs(topping + 1);
        } else {
            if (top_idx[root_no] > top_idx[root_yes]) swap(root_yes, root_no);
            if (proceed(topping, root_yes))
                return 1;
            else if (proceed(topping, root_no))
                return 1;
            else
                return 0;
        }
    }
    return 0;
}

void top_sort() {
    queue<int> q;
    for (int i = 1; i <= m; i++) {
        int r1 = res[BASE + i], r2 = res[BASE - i];
        for (int j : ke[r1]) in_cnt[j]++;
        for (int j : ke[r2]) in_cnt[j]++;
    }
    for (int i = 1; i <= m; i++) {
        int r1 = res[BASE + i], r2 = res[BASE - i];
        if (in_cnt[r1] == 0) q.push(r1);
        if (in_cnt[r2] == 0) q.push(r2);
    }
    while (!q.empty()) {
        int x              = q.front();
        top_res[++top_cnt] = x;
        q.pop();
        // cout << x << " ";
        for (int to : ke[x]) {
            // cout << to << " " << in_cnt[to] << endl;
            if ((--in_cnt[to]) == 0) q.push(to);
        }
    }
    for (int i = 1; i <= top_cnt; i++) top_idx[top_res[i]] = i;
}

int main() {
    char c1, c2;
    int a, b;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf(" %c %d %c %d", &c1, &a, &c2, &b);
        if (c1 == '-') a = -a;
        if (c2 == '-') b = -b;
        add_edge(a, b);
    }
    for (int i = 1; i <= m; i++) {
        if (!visited[BASE + i]) dfs(BASE + i);
        if (!visited[BASE - i]) dfs(BASE - i);
    }
    for (int i = 1; i <= m; i++) {
        int r1 = res[BASE + i] = get_root(BASE + i);
        int r2 = res[BASE - i] = get_root(BASE - i);
        if (r1 == r2) {
            puts("IMPOSSIBLE");
            return 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        convert_edge(BASE + i);
        convert_edge(BASE - i);
    }
    top_sort();
    // printf("kingdom of topping 1 top order Y%d=%d N%d=%d\n", res[BASE + 1],
    //        top_idx[res[BASE + 1]], res[BASE - 1], top_idx[res[BASE - 1]]);
    // for (int i = 1; i <= 10; i++) cout << top_res[i] << " ";
    // cout << endl;
    find_dfs(1);
}

