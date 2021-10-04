#include <bits/stdc++.h>
using namespace std;
struct edge {
    int a, b, weight;
    bool operator<(const edge &other) const { return weight < other.weight; }
};
int get_head(int a[], int i) {
    while (i != a[i]) i = a[i];
    return i;
}
int main() {
    int n, m;
    cin >> n >> m;
    int stack_pointer[n + 1];
    for (int i = 1; i <= n; i++) stack_pointer[i] = i;
    edge e[m];
    for (int i = 0; i < m; i++) cin >> e[i].a >> e[i].b >> e[i].weight;
    sort(e, e + m);
    int cnt = 0, res = 0;
    for (int i = 0; i < m; i++) {
        int a_head = get_head(stack_pointer, e[i].a);
        int b_head = get_head(stack_pointer, e[i].b);
        if (a_head == b_head) continue;
        res                   = max(res, e[i].weight);
        stack_pointer[b_head] = a_head;
        if (++cnt == n - 1) break;
    }
    cout << res;
}
