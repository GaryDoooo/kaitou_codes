#include<bits/stdc++.h>
using namespace std;
int pos[100005], n;
unsigned int dist_cache[40004] = {0};
unsigned int sum_dist(int shop) {
    if (dist_cache[shop]) return dist_cache[shop];
    register unsigned int res = 0;
    for (register unsigned int i = 0; i < n; i++) {
        res += abs(pos[i] - shop);
    }
    return    dist_cache[shop] = res;
}
inline int read() {
    int x = 0;//, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {/*if (ch == '-')f = -1;*/ ch = getchar();}
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x;// * f;
}
int main() {
    n = read();
    register int maxp = 0, minp = 1e9, mid;
    for (register unsigned int i = 0; i < n; i++) {
        pos[i] = read();
        maxp = max(pos[i], maxp);
        minp = min(pos[i], minp);
    }
    while (maxp > minp) {
        mid = (maxp + minp) >> 1;
        if (sum_dist(mid) < sum_dist(mid + 1)) {
            maxp = mid;
        } else {
            minp = mid + 1;
        }
    }
    cout << sum_dist(maxp) << endl;
}