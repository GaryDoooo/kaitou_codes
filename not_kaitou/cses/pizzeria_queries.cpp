#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MIN_INT -2147483648
using namespace std;
typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unordered_set<int> usint;
inline int read() {
    int xxxxx = 0, fffff = 1;
    char ccccch = getchar();
    while (!isdigit(ccccch)) {
        if (ccccch == '-') fffff = -1;
        ccccch = getchar();
    }
    while (isdigit(ccccch)) {
        xxxxx  = (xxxxx << 1) + (xxxxx << 3) + (ccccch ^ 48);
        ccccch = getchar();
    }
    return xxxxx * fffff;
}
inline void write(int x) {
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48);  // 48 是 '0'
    putchar(' ');
}
////////////////////////
int n, q, n0;
struct node {
    int pl, pr;  // best price from the tree most left and most right leaves
    int li, ri;  // most left and most right leaves' index of the sub tree on
                 // this node
};
node t[812345];

int main() {
    n = read(), q = read();
    n0 = (1 << (int)trunc(log2(n - 1)) + 1) - 1;
    for (int i = n0 + 1; i <= n + n0; i++) {
        t[i].pl = t[i].pr = read();
        t[i].li = t[i].ri = i;
    }
    for (int i = n0; i > 0; i--) {
        int l = i * 2, r = i * 2 + 1;
        t[i].li = t[l].li;
        t[i].ri = (t[r].ri > 0 ? t[r].ri : t[l].ri);
        t[i].pl = (t[r].pl > 0 ? min(t[l].pl, (t[r].li - t[l].li) + t[r].pl)
                               : t[l].pl);
        t[i].pr = (t[r].pr > 0 ? min(t[r].pr, (t[r].ri - t[l].ri) + t[l].pr)
                               : t[l].pr);
        // cout << i << ": li=" << t[i].li << " ri=" << t[i].ri
        //      << " pl=" << t[i].pl << " pr=" << t[i].pr << endl;
    }
    while (q--) {
        int a = read(), k = read() + n0;
        if (a == 1) {
            t[k].pl = t[k].pr = read();
            while (k > 1) {
                k     = k / 2;
                int l = k * 2, r = k * 2 + 1;
                // t[k].pl = min(t[l].pl, (t[r].li - t[l].li) + t[r].pl);
                // t[k].pr = min(t[r].pr, (t[r].ri - t[l].ri) + t[l].pr);
                t[k].pl =
                    (t[r].pl > 0 ? min(t[l].pl, (t[r].li - t[l].li) + t[r].pl)
                                 : t[l].pl);
                t[k].pr =
                    (t[r].pr > 0 ? min(t[r].pr, (t[r].ri - t[l].ri) + t[l].pr)
                                 : t[l].pr);
            }
        } else {
            int pl = t[k].pl, pr = t[k].pr, idx = k;
            while (k > 1) {
                k     = k / 2;
                int l = k * 2, r = k * 2 + 1;
                if (t[r].li >= idx) pl = min(pl, (t[r].li - idx) + t[r].pl);
                if (t[l].ri <= idx) pr = min(pr, idx - t[l].ri + t[l].pr);
            }
            // cout << pl << " " << pr << endl;
            write(min(pl, pr));
        }
    }
}

