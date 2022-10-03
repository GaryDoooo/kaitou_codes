#include<cstdio>
#include <iostream>
using namespace std;
int n, m, l, r, L, mid;
int d[100005];

bool check(int mid) {
    int cnt = 0;
    int last = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (d[i] - d[last] < mid) {
            cnt++;
            if (cnt > m) return false;
        } else last = i;
    }
    return true;
}
int main() {
    scanf("%d %d %d", &L, &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &d[i]);
    d[n + 1] = L;
    l = 0; r = L + 10;
    while (r - l > 1) {
        mid = (r + l) / 2;
        if (check(mid))
            l = mid;
        else r = mid;
    }
    printf("%d\n", l);
    int last = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (d[i] - d[last] >= l) {
            last = i;
            cout << d[i] << " ";
            // cout <<
            // if (cnt > m) return false;
            // } else last = i;
        }
    }
}