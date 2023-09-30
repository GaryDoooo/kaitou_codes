#include <bits/stdc++.h>
using namespace std;
struct node {
    int l, r;
    long long sum;
    long long add_by;
    int step;
};
int n, q, b, a[212345];
node t[812345];

void push_down(int u) {
    if (t[u].add_by == 0) return;
    t[u].sum += (t[u].add_by + t[u].add_by + (t[u].r - t[u].l) * t[u].step) *
                (t[u].r - t[u].l + 1) / 2;
    if (t[u].l < t[u].r) {
        int l = u << 1, r = u << 1 | 1;
        t[l].add_by += t[u].add_by;
        t[r].add_by += t[u].add_by + (t[r].l - t[u].l) * t[u].step;
        t[r].step += t[u].step;
        t[l].step += t[u].step;
    }
    t[u].step = t[u].add_by = 0;
}

void bringup(int u) {
    int l = u << 1, r = u << 1 | 1;
    push_down(l), push_down(r);
    t[u].sum = t[l].sum + t[r].sum;
}

void build(int u, int l, int r) {
    t[u] = {l, r, 0, 0, 0};
    if (l == r) {
        t[u].sum = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    bringup(u);
}

void add_x(int u, int l, int r) {
    push_down(u);
    if (t[u].l >= l and t[u].r <= r) {
        t[u].add_by = 1 + t[u].l - l;
        t[u].step   = 1;
        return;
    }
    int mid = t[u].l + t[u].r >> 1;
    if (mid >= l) add_x(u << 1, l, r);
    if (mid < r) add_x(u << 1 | 1, l, r);
    bringup(u);
}

long long query(int u, int l, int r) {
    push_down(u);
    if (t[u].l >= l and t[u].r <= r) return t[u].sum;
    int mid       = t[u].l + t[u].r >> 1;
    long long res = 0;
    if (mid >= l) res = query(u << 1, l, r);
    if (mid < r) res += query(u << 1 | 1, l, r);
    return res;
}

void push_all_down(int u) {
    push_down(u);
    if (t[u].l < t[u].r) {
        push_all_down(u << 1);
        push_all_down(u << 1 | 1);
    }
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    build(1, 1, n);
    while (q--) {
        scanf("%d", &b);
        if (b == 1) {
            int l, r;
            scanf("%d %d", &l, &r);
            add_x(1, l, r);
        } else if (b == 2) {
            int l, r;
            scanf("%d %d", &l, &r);
            // push_all_down(1);
            printf("%lld\n", query(1, l, r));
        }
    }
}
/* ;lakjsdf;lj ;alksjdf;lakjsdf;lkjas;dlkfja;lskdjf;laksjdf;lkjas;ldkfja;lsdkjf;alskdjfa;lskdjf;alksdjf;alksjdf;laksjdf;laksjdf;laksjdf;lkajsd;flkjas;ldkjfa;lskdjf;lasjd;lkfj;lkjs;ldkjfa;lskdjf;lksjdf;
 * as;dlfkjas;ldkjfa;lskjdf;alskjdf;alkjsdf;lakjs;dlfkja;lskdjf;alskjdf;lakjsdf;lkajsd;lkjfkljsdl;kfjal;skdjf;lkjs;dalkfja;slkdjfa;slkdfj
 *
 * a;lskdjf;alskjdf;lakjsdf;ljaksd;lfkja;lskdjfl;aksjdfl;kajiejfa;lksjdfl;kajsd;lkfja;sldkjf;alksjdf
 * ;lkasjdf;lkajs;dlfjka;lskdjf;alskdjf
 * j;alskdjf;alkjsdf;lakjsdf;lkjals;kdjfalkiejijfiejfk;lje;lkfjas;ldkjfa;lskdjf
 * a;lskdjf;alksjdf;laksjdf;lakjsdf;lkjas;ldkjfa;lsdkjfa;lksdjfa;liejl;iaej;aflksdjfl;ka
 * a;lskdjfa;lsdijfio;asjdf;ljxlkjv;lxkncv,zxnc.v,mnzkjhds;lajfalsdjf asjdfkl as;ldkfj a;lksdj f
 * jfeipjawioejfas kdjfa;lksjf
 * a;lksdjf;alksjdf 
 * a;lskdjf;alksdjf 
 * a;lskdfjl;aksjdf;lakjsd;lfkja;lskdjf ;akjd;lfkjasd;lkfj;lsakdjfl;aksjdfl;kasn,m.xzcnv.,zmxncv.,mnv;lkajsdf;lakjsdfl;kjsad
 * f;lkasjdf;lakjsdfl;kjnz,.xmncvklsdjfa;lksdjfl;ksadf
 * ;lzkv;lkxjcv;lkj;lksajdf;laksjdflk;ajsdf
 *
  */

