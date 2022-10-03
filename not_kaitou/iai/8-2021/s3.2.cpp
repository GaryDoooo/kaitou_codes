#include <bits/stdc++.h>
using namespace std;
struct day {
    int a, p, c, sold;
    bool operator>(day other) const { return p > other.p; }
};
int main() {
    int n, p, a, c;
    cin >> n;
    priority_queue<day, vector<day>, greater<day>> q;
    long long inventory = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> p >> c;
        inventory += a;
        int sold = min(inventory, (long long)c);
        inventory -= sold;
        if (inventory == 0) {
            int demand = c - sold;
            while (demand > 0 and !q.empty()) {
                day q_top = q.top();
                if (q_top.p >= p) break;
                q.pop();
                int move_sold = min(q_top.sold, demand);
                demand -= move_sold;
                q_top.sold -= move_sold;
                sold += move_sold;
                if (q_top.sold > 0) q.push(q_top);
            }
        }
        q.push(day{a, p, c, sold});
    }
    long long gain = 0;
    while (!q.empty()) {
        gain += q.top().p * q.top().sold;
        q.pop();
    }
    cout << gain;
}

