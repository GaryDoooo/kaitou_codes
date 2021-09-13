#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0;//, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) { ch = getchar();}
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x;// * f;
}
int main() {
    int n = read(), m = read();
    // int p[4000005]; //# of person come at this second
    // int w[4000005]; // shortest wait time if bus leave at this second
    // int l[4000105]; // # of person have to wait if bus leave at this second
    // memset(p, 0, sizeof(p));
    // memset(w, 0, sizeof(w));
    // memset(l, 0, sizeof(l));
    vector<int> p(4000005, 0), w(4000105, 0), l(4000105, 0);
    int max_t = 0, ti;
    for (int i = 0; i < n; i++) max_t = max(max_t, ti = read()), p[ti_i]++;
}