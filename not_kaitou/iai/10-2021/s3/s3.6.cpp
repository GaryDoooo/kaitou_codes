#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x  = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x;
}
int main() {
    int n = read(), m = read();
    long long res = 0, sum = 0, t1 = 0, t2 = 0, t3 = 0;
    int reserve_start = 0;
    multiset<long long> temp;
    vector<multiset<long long>> Btree;
    vector<int> bt_sums;
    for (int i = 1; i <= n; i++) {
        sum += read() - m;
        res += (sum >= 0);
        bool not_added = true;
        for (int j = Btree.size() - 1; j >= 0; j--) {
            if (sum < *(Btree[j].begin()) and j > 0) continue;
            auto it = Btree[j].upper_bound(sum);
            res += distance(Btree[j].begin(), it);
            if (it != Btree[j].end()) {
                not_added = false;
                Btree[j].insert(sum);
                for (int k = j; k < bt_sums.size(); k++) bt_sums[k]++;
            }
            if (j > 0) res += bt_sums[j - 1];
            break;
        }
        if (not_added) {
            auto it = temp.upper_bound(sum);
            res += distance(temp.begin(), it);
            temp.insert(sum);
            if (temp.size() > 150) {
                multiset<long long> temp_copy(temp);
                Btree.push_back(temp_copy);
                if (bt_sums.size() > 0)
                    bt_sums.push_back(temp.size() + bt_sums.back());
                else
                    bt_sums.push_back(temp.size());
                temp.clear();
            }
        }
    }
    cout << res << endl;
}
