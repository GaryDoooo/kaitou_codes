#include <bits/stdc++.h>
using namespace std;
struct node {
    long long pos, change;
};
vector<node> a;
bool operator<(const node& a, const node& b) {
    if (a.pos != b.pos) return a.pos < b.pos;
    return a.change > b.change;
}
long long res, in_pos, n, i1, i2, fire_cnt;
int main() {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &i1, &i2);
        a.push_back({i1, 1});
        a.push_back({i2, -1});
    }
    sort(a.begin(), a.end());
    // for (int i = 0; i < a.size();, i++) {
    for (auto i : a) {
        if (fire_cnt == 0 and i.change == 1) in_pos = i.pos;
        if (fire_cnt == 1 and i.change == -1) res += i.pos - in_pos;
        fire_cnt += i.change;
    }
    cout << res << endl;
}

