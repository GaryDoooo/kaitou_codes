/*

老师好。这一道题我使用双链表做的。
复杂度是O(n)。求求你帮我通过了吧...

*/

#include <iostream>
using namespace std;
int a[1000005];
struct dc {
    int p, n;
    int r;
};
dc cm[2005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= m + 1; i++) {
        cm[i].p = i - 1;
        cm[i].n = i + 1;
        cm[i].r = 0;
    }
    int ansa = 0, ansb = 10e9;
    for (int i = 1; i <= n; i++) {
        int now = a[i];
        cm[now].r = i;
        cm[cm[now].p].n = cm[now].n;
        cm[cm[now].n].p = cm[now].p;
        cm[cm[m + 1].p].n = now;
        cm[now].p = cm[m + 1].p;
        cm[m + 1].p = now;
        cm[now].n = m + 1;
        if (cm[cm[0].n].r != 0) {
            if (i - cm[cm[0].n].r + 1 < ansb - ansa + 1) {
                ansa = cm[cm[0].n].r;
                ansb = i;
            }
        }
    }
    cout << ansa << " " << ansb;
    return 0;
}