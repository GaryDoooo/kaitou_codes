#include <bits/stdc++.h>
using namespace std;
map<int, int> cnt;
int n, x, w[22], res = 1e9, res_cnt;
map<int, multiset<int>> m, mb;
// multiset<int> person;
vector<int> ss[30];
vector<int> mlist;

void print_m() {
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << ": ";
        for (int i : it->second) cout << i << " ";
        cout << endl;
    }
}
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
void print(int x) {
    print_m();
    cout << " picked: ";
    for (int i : ss[x]) cout << i << " ";
    // while (!ss.empty()) cout << ss.top() << " ", ss.pop();
    cout << endl;
}
void remove_vector(vector<int> &a, int x) {
    for (auto it = a.begin(); it != a.end(); ++it)
        if (*it == x) {
            a.erase(it);
            return;
        }
}

bool dfs(int person_left, int sum, int cart_on_loading, bool head) {
    // cout << person_left << " " << sum << " " << cart_on_loading << endl;
    if (cart_on_loading > res)
        return true;
    else if (person_left == 0) {
        // print(cart_on_loading);
        // cout << "done" << endl;
        res = min(res, cart_on_loading);
        // cout << "intermediate " << res << endl;
        if (++res_cnt > 200) {
            cout << res << endl;
            exit(0);
        } else
            return true;
    } else if (sum == 0) {
        // or m[sum].size() == 0) {  // and sum < *person.begin())
        // print(cart_on_loading);
        bool good = false;
        do {
            int temp = get_available_sum();
            // cout << "start new at sum " << temp << endl;
            good = dfs(person_left, temp, cart_on_loading + 1, true);
        } while (!good);
        return true;
    } else if (m[sum].size() == 0)
        return false;
    else {
        // cout << m[sum].size() << endl;
        // if (m[sum].size() == 0) return;
        vector<int> todo(m[sum].rbegin(), m[sum].rend());
        bool have_trues = false;
        for (int i : todo) {
            // cout << sum << " " << person_left<<" "m[sum]. << "here" << endl;
            vector<int> affected_sums = remove(i);
            // person.erase(person.find(i));
            ss[cart_on_loading].push_back(i);
            bool good = dfs(person_left - 1, sum - i, cart_on_loading, false);
            have_trues |= good;
            ss[cart_on_loading].pop_back();
            if (head and !good) remove_vector(affected_sums, sum);
            for (int j : affected_sums) m[j].insert(i);
            // person.insert(i);
        }
        return have_trues;
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
    // person.insert(w, w + n);
    // dfs(n, get_available_sum(), 1, true);
    mb = m;
    for (auto it = m.rbegin(); it != m.rend(); ++it)
        if (it->firs) mlist.push_back(it->first);
    for (int i = 0; i < min(2, n); i++) {
        m = mb;
        // cout << "start: " << i << endl;
        dfs(n, todo[i], 1, true);
    }
    cout << res;
}
