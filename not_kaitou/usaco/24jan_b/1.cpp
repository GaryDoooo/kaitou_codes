#include <bits/stdc++.h>
using namespace std;
int t, n, a[112345];
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int b;
        set<int> res;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b);
            if (a[b] == 0)
                a[b] = i;
            else {
                if (i - a[b] <= 2)
                    res.insert(b);
                else
                    a[b] = i;
            }
        }
        if (res.size()) {
            vector<int> res1;
            for (int i : res) res1.push_back(i);
            for (int i = 0; i < res1.size() - 1; i++) printf("%d ", res1[i]);
            printf("%d\n", res1.back());
        } else
            printf("-1\n");
    }
}

