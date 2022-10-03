#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll w_sum[212345], c_sum[212345], d_sum[212345], res = ULLONG_MAX, f2[212345];
int w[212345], d[212345], n, q[212345], head = 1, tail;
struct line {
    ll a, b, x = 0;
};
line l[212345];

ll cost(int start, int end) {
    if (end <= start) return 0;
    return c_sum[end] - c_sum[start - 1] -
           w_sum[start - 1] * (d_sum[end] - d_sum[start - 1]);
}
ll get_x(int newp, int oldp) {
    return l[newp].x = (ll)ceil(((double)l[newp].b - (double)l[oldp].b) /
                                ((double)l[newp].a - (double)l[oldp].a));
    // return l[newp].x = (l[newp].b - l[oldp].b) / (l[newp].a - l[oldp].a);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &w[i], &d[i]);
    for (int i = 1; i <= n + 1; i++) {
        c_sum[i] = c_sum[i - 1] + w_sum[i - 1] * d[i - 1];
        w_sum[i] = w_sum[i - 1] + w[i];
        d_sum[i] = d_sum[i - 1] + d[i - 1];
        l[i].a   = w_sum[i];
        l[i].b   = w_sum[i] * d_sum[i];
    }
    q[++tail] = 1;
    for (int i = 2; i <= n; i++) {
        // cout << "i " << i << " ";
        // for (int j = head; j <= tail; j++)
        //     cout << "q[i]" << q[j] << "x" << l[q[j]].x << " ";
        // cout << endl;
        while (tail > head and l[q[head + 1]].x <= d_sum[i]) head++;
        while (tail >= head and get_x(i, q[tail]) < l[q[tail]].x) tail--;
        q[++tail] = i;
        int f1    = q[head];
        f2[i]     = cost(1, f1) + cost(f1 + 1, i);
        // for (int j = head; j <= tail; j++)
        //     cout << "q[i]" << q[j] << "x" << l[q[j]].x << " ";
        // cout << "f2=" << f2[i] << endl;  // endl;
    }
    for (int i = 2; i <= n; i++) res = min(res, f2[i] + cost(i + 1, n + 1));
    cout << res << endl;
}
// for (int i = 1; i <= n + 1; i++) {
//     for (int j = i; j <= n + 1; j++)
//         cout << i << "->" << j << "=" << cost(i, j) << " ";
//     cout << endl;
//     int c = 1e9, m;
//     for (int j = 1; j <= i; j++) {
//         int cc = cost(1, j) + cost(j + 1, i);
//         if (cc < c) {
//             c = cc;
//             m = j;
//         }
//     }
//     cout << f2[i] << " " << m << endl;
// }
//
//
// f1 = 1;
// for (int i = 3; i <= n; i++) {
//     ll now_c   = cost(1, f1) + cost(f1 + 1, i), new_c;
//     int now_f1 = f1, new_f1;
//     bool found;
//     // do {
//     new_f1 = now_f1 + 1;
//     while (new_f1 < i) {
//         new_c = cost(1, new_f1) + cost(new_f1 + 1, i);
//         if (new_c <= now_c) {
//             now_c  = new_c;
//             now_f1 = new_f1;
//         } else
//             break;
//         new_f1++;
//     }
//     f1    = now_f1;
//     f2[i] = now_c;
// }
