#include <bits/stdc++.h>
using namespace std;
int f_max[100005][20], f_min[100005][20];
int n, K, max_range, cnt, ans[100005];
int diff(int a, int b) {
    int j            = trunc(log2(b - a + 1));
    int k            = 1 << j;
    int max_in_range = max(f_max[a][j], f_max[b - k + 1][j]);
    int min_in_range = min(f_min[a][j], f_min[b - k + 1][j]);
    // cout << "a " << a << " b " << b << " " << max_in_range << " "
    //      << min_in_range << endl;
    return max_in_range - min_in_range;
}
// int find_max_range() {
//     for (int j = trunc(log2(n)); j >= 0; j--) {
//         for (int i = 1; i <= n and f_min[i][j]; i++) {
//             if (f_max[i][j] - f_min[i][j] <= K) {
//                 return 1 << j;
//             }
//         }
//     }
// }
//
// bool test(int range) {
//     for (int start = 1; start + range <= n; start++) {
//         // for (int range = max_range; start + range <= n; range++) {
//         int temp = diff(start, start + range);
//         if (temp <= K) return true;
//     }
//     return false;
// }
int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &f_max[i][0]);
    memcpy(f_min, f_max, sizeof(f_min));
    for (int k = 1, j = 1; k < n; k <<= 1, j++) {
        for (int i = 1; i + k <= n; i++) {
            f_max[i][j] = max(f_max[i][j - 1], f_max[k + i][j - 1]);
            f_min[i][j] = min(f_min[i][j - 1], f_min[k + i][j - 1]);
        }
    }
    int start, end;
    for (int i = 1; i <= K; i++) {
        scanf("%d%d", &start, &end);
        printf("%d\n", diff(start, end));
    }
    // max_range = find_max_range() - 1;
    // cout << max_range << endl;
    // int left = 1, right = n - 1;
    // while (left < right) {
    //     int mid = (left + right + 1) / 2;
    //     // cout << left << " " << right << " " << test(mid) << endl;
    //     if (test(mid)) {
    //         left = mid;
    //     } else {
    //         right = mid - 1;
    //     }
    // }
    // max_range = left;

    // for (int start = 1; start + max_range <= n; start++)
    //     if (diff(start, start + max_range) <= K) ans[cnt++] = start;
    // printf("%d %d\n", max_range + 1, cnt);
    // for (int i = 0; i < cnt; i++) printf("%d %d\n", ans[i], ans[i] +
    // max_range); for (int k = 0; k < 3; k++) {
    //     for (int i = 0; i <= n; i++) printf("%d ", f_max[i][k]);
    //     puts("");
    // }
    // puts("");
    // for (int k = 0; k < 3; k++) {
    //     for (int i = 0; i <= n; i++) printf("%d ", f_min[i][k]);
    //     puts("");
    // }
}

