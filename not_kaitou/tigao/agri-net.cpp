#include <bits/stdc++.h>
using namespace std;
struct edge {
    int a, b, w;
    bool operator<(const edge& e) const { return w < e.w; }
};
int find_head(int a[], int i) {
    while (i != a[i]) i = a[i];
    return i;
}
int main() {
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];
    vector<edge> edges;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++) edges.push_back({j, i, a[i][j]});
    sort(edges.begin(), edges.end());
    int stack_pointers[n + 1];
    long long res = 0, cnt = 0;
    for (int i = 0; i <= n; i++) stack_pointers[i] = i;
    for (auto e : edges) {
        int a_head = find_head(stack_pointers, e.a);
        int b_head = find_head(stack_pointers, e.b);
        if (a_head == b_head) continue;
        res += e.w;
        stack_pointers[a_head] = b_head;
        if (++cnt == n - 1) break;
    }
    cout << res << endl;
}
