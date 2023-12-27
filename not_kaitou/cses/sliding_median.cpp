#include <bits/stdc++.h>
using namespace std;
int n, k, a[212345];
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int b[k];
    for (int i = 0; i < k; i++) b[i] = a[i];
    sort(b, b + k);
    int kk = (k > 1 ? k + 1 >> 1 : 1);
    multiset<int> sl(b, b + kk), sr(b + kk, b + k);
    int median = b[kk - 1];
    cout << median << " ";  // << kk << " ";
    for (int i = k; i < n; i++) {
        if (a[i - k] <= median)
            sl.erase(sl.lower_bound(a[i - k]));
        else
            sr.erase(sr.lower_bound(a[i - k]));
        if (a[i] <= median)
            sl.insert(a[i]);
        else
            sr.insert(a[i]);
        while (sl.size() > kk) {
            auto it = sl.end();
            sr.insert(*(--it));
            sl.erase(it);
        }
        while (sl.size() < kk) {
            sl.insert(*sr.begin());
            sr.erase(sr.begin());
        }
        auto it = sl.end();
        printf("%d ", median = *(--it));
    }
}
