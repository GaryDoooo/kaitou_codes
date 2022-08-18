#include <bits/stdc++.h>
#define ll __int128
using namespace std;
int n, temp;
ll a[60], f[60][60];
std::ostream& operator<<(std::ostream& o, const __int128& x) {
    if (x == std::numeric_limits<__int128>::min())
        return o << "-170141183460469231731687303715884105728";
    if (x < 0) return o << "-" << -x;
    if (x < 10) return o << (char)(x + '0');
    return o << x / 10 << (char)(x % 10 + '0');
}
ll product(int a1, int a2, int a3) {
    // cout << a1 << " " << a2 << " " << a3 << std::endl;
    return a[a1] * a[a2] * a[a3];
}

ll max_ans(int head, int tail) {
    if (f[head][tail] > 0) return f[head][tail];
    int head_right = (head + 1) % n;
    int tail_left  = (tail - 1 + n) % n;
    // cout << head << " " << tail << " " << head_right << " " << tail_left
    //      << std::endl;
    if (head_right == tail_left)
        return f[head][tail] = product(head_right, head, tail);
    ll res = 2e33;
    for (int i = head_right; i != tail; i++) {
        ll r = product(i, head, tail);
        if (i != head_right) r += max_ans(head, i);
        if (i != tail_left) r += max_ans(i, tail);
        res = min(res, r);
    }
    return f[head][tail] = res;
    // return f[head][tail] =
    //            min(product(head, head_right, tail) + max_ans(head_right,
    //            tail),
    //                product(tail, tail_left, head) + max_ans(head,
    //                tail_left));
}

int main() {
    scanf("%d", &n);
    // cout << n << "_";
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        // cout << temp << "_";
        a[i] = temp;
    }
    cout << max_ans(0, n - 1) << std::endl;
    // memset(a, 1, sizeof(a));
    // cout << a[1] << endl;
    // if (n > 3) {
    // ll res = 2e33;
    // for (int i = 0; i < n; i++) {
    //     int right = (i + 1) % n, left = (i + n - 1) % n;
    //     res = min(product(i, left, right) + max_ans(right, left), res);
    // }
    // // cout << max_ans(1, n - 1) << endl;
    // cout << res << endl;
    // } else
    // cout << product(0, 1, 2);
}
