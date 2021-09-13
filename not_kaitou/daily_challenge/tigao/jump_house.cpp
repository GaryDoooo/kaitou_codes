#include <bits/stdc++.h>
#define INF 9223372036854775807
using namespace std;
static int pos[500005], val[500005];
static long long b[500005], current_max;
int n, k, d;
bool got_k(int g) {
    int longest = d + g, shortest = max(1, d - g);
    register int left = 0, right = 0;
    current_max = 0;
    for (register int i = 1; i <= n; i++) {
        while (pos[i] - pos[right + 1] >= shortest) {
            current_max = max(current_max, b[++right]);
        }
        while (pos[i] - pos[left] > longest) {
            left++;
            if (left == i) return false;
            if (b[left - 1] == current_max) {
                current_max = *max_element(b + left, b + right + 1);
            }
        }
        if ((left == right and pos[i] - pos[right] < shortest)
                or current_max < -5e10 or left > right) {
            b[i] = -INF;
            continue;
        }
        b[i] = current_max + val[i];
        if (b[i] >= k) return true;
    }
    return false;
}
int main() {
    // cin >> n >> d >> k;
    scanf("%d %d %d\n", &n, &d, &k);
    pos[0] = 0; val[0] = 0; b[0] = 0;
    for (register int i = 1; i <= n; i++) scanf("%d %d\n", pos + i, val + i);
    int left = 0, right = pos[n] - d, res = 2e9;
    while (left < right) {
        int mid = (left + right) / 2;
        if (got_k(mid)) {
            res = min(res, mid);
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << (res == 2e9 ? -1 : res);
    return 0;
}