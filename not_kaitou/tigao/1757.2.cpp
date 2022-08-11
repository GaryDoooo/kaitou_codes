#include <bits/stdc++.h>
using namespace std;
struct node {
    int k;      // n is same to all
    int a[15];  // coin values
    int b[15];  // continues value acheivable by at least N coins
};
int n, head = 1, tail = 1, res = 1;
node a[100005];
int main() {
    int k;
    scanf("%d%d", &n, &k);
    a[1].k    = 1;
    a[1].a[1] = 1;
    for (int i = 0; i <= n; i++) a[1].b[i] = i;
    while (head <= tail) {
        node t = a[head++];
        if (t.k == k) {
            if (t.b[n] > a[res].b[n]) res = head - 1;
            continue;
        }
        // for (int i = 1; i <= n; i++) {
        for (int i = t.b[n] + 1; i > t.k; i--) {
            node *now = a + (++tail);
            now->k    = t.k + 1;
            memcpy(now->a, t.a, sizeof(int) * 15);
            now->a[t.k + 1] = i;
            bitset<1000> s[15];
            s[0][0] = true;
            // cout << s[0] << endl;
            for (int p = 1; p <= n; p++)
                for (int j = 1; j <= now->k; j++) {
                    s[p] |= s[p - 1] << (now->a[j]);
                    // for (int l : s[p - 1]) {
                    // s[p].insert(l + now->a[j]);
                    // all.insert(l + now->a[j]);
                    // }
                }
            for (int p = 1; p <= n; p++) s[0] |= s[p];
            int cnt = 0;
            // cout << s[0] << endl;
            while (1) {
                s[0] >>= 1;
                if (s[0][0])
                    cnt++;
                else
                    break;
            }

            // for (int l : all) {
            //     if (l != last + 1) break;
            //     last = l;
            // }
            now->b[n] = cnt;

            // a[tail].a[t.k + 1] = t.b[i] + 1;
            // now->b[0] = 0;
            // for (int j = 1; j <= n; j++) {
            //     now->b[j]      = t.b[j];
            //     int multiplier = 0;
            //     while ((multiplier + 1) * i <= now->b[j] + 1 and
            //            multiplier < j) {
            //         multiplier++;
            //         now->b[j] =
            //             max(now->b[j], multiplier * i + now->b[j -
            //             multiplier]);
            //     }
            // }
        }
    }
    for (int i = 1; i <= k; i++) {
        cout << a[res].a[i] << " ";
    }
    cout << endl << "MAX=" << a[res].b[n] << endl;
}
