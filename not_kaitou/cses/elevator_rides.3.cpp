#include <bits/stdc++.h>
using namespace std;
map<int, int> cnt;
int n, x, w[22], res = 1e9, res_cnt;
map<int, multiset<int>> m;
multiset<int> person;

int get_available_sum() {
    auto it = m.end();
    for (it--; it != m.begin(); it--) {
        if (it->second.empty()) continue;
        return it->first;
    }
    return 0;
}
vector<int> remove(int x) {
    vector<int> res;
    for (auto it = m.begin(); it != m.end(); ++it) {
        auto it2 = it->second.find(x);
        if (it2 != it->second.end()) {
            it->second.erase(it2);
            res.push_back(it->first);
        }
    }
    return res;
}

void dfs(int person_left, int sum, int cart_on_loading) {
    // cout << person_left << " " << sum << " " << cart_on_loading << endl;
    if (cart_on_loading > res) return;
    if (person_left == 0) {
        res = min(res, cart_on_loading);
        if (++res_cnt > 20) {
            cout << res << endl;
            exit(0);
        } else
            return;
    }
    if (sum == 0 or m[sum].size() == 0 and sum < *person.begin())
        dfs(person_left, get_available_sum(), cart_on_loading + 1);
    else {
        // cout << m[sum].size() << endl;
        // if (m[sum].size() == 0) return;
        vector<int> todo(m[sum].rbegin(), m[sum].rend());
        for (int i : todo) {
            // cout << sum << " " << person_left<<" "m[sum]. << "here" << endl;
            vector<int> affected_sums = remove(i);
            person.erase(person.find(i));
            dfs(person_left - 1, sum - i, cart_on_loading);
            for (int j : affected_sums) m[j].insert(i);
            person.insert(i);
        }
    }
}

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        cnt[w[i]]++;
    }
    m[0].insert(0);
    sort(w, w + n);
    for (int j = 0; j < n; j++) {
        vector<pair<int, int>> todo;
        for (auto it = m.begin(); it != m.end(); ++it)
            if (w[j] + it->first > x)
                break;
            else
                todo.push_back(make_pair(w[j] + it->first, w[j]));
        for (auto &p : todo) m[p.first].insert(p.second);
    }
    person.insert(w, w + n);
    // for (auto it = m.begin(); it != m.end(); ++it) {
    //     cout << it->first << ": ";
    //     for (int i : it->second) cout << i << " ";
    //     cout << endl;
    // }
    dfs(n, get_available_sum(), 1);
    cout << res;
}
