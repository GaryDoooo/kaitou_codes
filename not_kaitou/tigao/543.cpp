#include <algorithm>
#include <iostream>
using namespace std;
struct fish {
    int v, d;
};
bool operator<(fish const& a, fish const& b) {
    if (a.v < b.v)
        return a.d * 2 > b.d;
    else if (a.v > b.v)
        return a.d > b.d * 2;
    else
        return a.d > b.d;
}

int main() {
    int n, v, last_v1 = -1, total_v = 0, res = 0;
    cin >> n >> v;
    fish f[n];
    for (int i = 0; i < n; i++) cin >> f[i].v >> f[i].d;
    sort(f, f + n);
    for (int i = 0; i < n; i++) {
        if (total_v < v - 1 or (total_v == v - 1 and f[i].v == 1)) {
            res += f[i].d;
            total_v += f[i].v;
            if (f[i].v == 1) last_v1 = i;
        } else if (total_v == v)
            break;
        else {
            int next_2 = i;
            if (last_v1 == -1) break;
            if (f[last_v1].d >= f[i].d) break;
            int found_nxt_1 = -1;
            while (i < n) {
                if (f[i].v == 2)
                    i++;
                else {
                    found_nxt_1 = i;
                    break;
                }
            }
            if (found_nxt_1 == -1) {
                res -= f[last_v1].d;
                res += f[next_2].d;
                break;
            } else if (f[found_nxt_1].d + f[last_v1].d >= f[next_2].d) {
                res += f[found_nxt_1].d;
                break;
            } else {
                res -= f[last_v1].d;
                res += f[next_2].d;
                break;
            }
        }
    }
    cout << res << endl;
}

