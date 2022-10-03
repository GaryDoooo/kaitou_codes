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
struct cache {
    int value = -1;
};
unordered_map<ull, cache> m;
bool can_sum(int index, int sum, int a[], int acc[]) {
    // cout << index << " " << sum << "    ";
    if (index < 0 or sum < 0 or acc[index] < sum) return false;
    // if (sum==0) return true;
    ull index_sum = ((ull)sum << 12) + index;
    if (m[index_sum].value > 0) return m[index_sum].value;
    m[index_sum].value =
        ((a[index] == sum) or can_sum(index - 1, sum, a, acc) or
         can_sum(index - 1, sum - a[index], a, acc));
    return m[index_sum].value;
}
int main() {
    int n = read();
    int a[n], acc[n];
    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i] = read();
    int target = (sum & 1 ? sum / 2 + 1 : sum / 2);
    // int v[n + 1];
    sort(a, a + n);
    acc[0] = a[0];
    for (int i = 1; i < n; i++) acc[i] = a[i] + acc[i - 1];
    while (target < sum) {
        // m.clear();
        // cout << "look at " << target << endl;
        if (can_sum(n - 1, target, a, acc)) {
            cout << target;
            return 0;
        } else
            target++;
    }

    // memset(v, 0, sizeof(v));
    // for (int i = 0; i < n; i++) {
    //     for (int j = n; j > 0; j--)
    //         if (abs(target - (v[j - 1] + a[i])) < abs(target - (v[j])))
    //             v[j] = v[j - 1] + a[i];
    //     for (int j = 1; j <= n; j++) cout << v[j] << " ";
    //     cout << endl;
    // }
    // int res = 0;
    // cout << "sum=" << sum << " target=" << target << endl;
    // for (int i = 1; i <= n; i++) {
    //     // cout << v[i] << " ";
    //     if (abs(res - target) > abs(v[i] - target)) res = v[i];
    // }
    // cout << res;
}
