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

int main() {
    int n = read();
    int a[n], sum = 0, acc[n], half_sum = 0;
    for (int i = 0; i < n; i++) sum += a[i] = read();
    sort(a, a + n);
    acc[0] = a[0];
    for (int i = 1; i < n; i++) {
        if (half_sum)
            acc[i] = half_sum + a[i];
        else {
            acc[i] = a[i] + acc[i - 1];
            if (acc[i] > sum / 2) half_sum = acc[i];
        }
    }
    vector<int> can_sum(sum, 0);
    can_sum[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = acc[i]; j >= a[i]; j--)
            if (can_sum[j - a[i]]) can_sum[j] = 1;
    }
    for (int target = (sum & 1 ? sum / 2 + 1 : sum / 2); target <= sum;
         target++) {
        if (can_sum[target]) {
            cout << target;
            return 0;
        }
    }
}
