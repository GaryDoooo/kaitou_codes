#include <bits/stdc++.h>
using namespace std;
int s[1000005], minimum[1000005], n, a, res, q[1000005], tail;
int main() {
    scanf("%d", &n);
    minimum[0] = 1e9;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        s[i]       = s[i - 1] + a;
        minimum[i] = min(minimum[i - 1], s[i]);
        while (tail > 0) {
            if (s[q[tail] - 1] > s[i])
                tail--;
            else
                break;
        }
        if (a >= 0) q[++tail] = i;
    }
    while (tail > 0) {
        int k            = q[tail--];
        int sum_k_to_end = s[n] - s[k - 1];
        if (s[k] - s[k - 1] < 0 or sum_k_to_end < 0) continue;
        res += sum_k_to_end >= -minimum[k - 1];
        // if (sum_k_to_end >= -minimum[k - 1])
        //     cout << k << " " << q.top().sum << " " << minimum[k - 1] << " "
        //          << s[n] - s[k - 1] << endl;
    }
    printf("%d\n", res);
}
