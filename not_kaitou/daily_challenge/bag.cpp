#include <bits/stdc++.h>
using namespace std;
// int read() {char c; int x = 0; while ((c = getchar()) > 47) x = x * 10 + (c ^ 48); return x;}
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-')f = -1; ch = getchar();}
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x * f;
}
struct item {
    int weight, value, ratio;
};
bool cmp(item const &a, item const &b) { return a.weight < b.weight; }
void dfs(int *max_value, item items[], int n, int max_weight, int i, int sum_weight,
         int sum_value) {
    if (i >= n or sum_weight + items[i].weight > max_weight) {*max_value = max(*max_value, sum_value); return;}
    // if ()
    //     *max_value = max(*max_value, sum_value);
    dfs(max_value, items, n, max_weight, i + 1, sum_weight + items[i].weight, sum_value + items[i].value);
    dfs(max_value, items, n, max_weight, i + 1, sum_weight, sum_value);
}
int main() {
    int max_weight = read(), n = read();
    int max_value = 0;
    item items[n];
    for (int i = 0; i < n; i++) items[i].weight = read(), items[i].value = read();
    sort(items, items + n, cmp);
    dfs(&max_value, items, n, max_weight, 0, 0, 0);
    cout << max_value;
}