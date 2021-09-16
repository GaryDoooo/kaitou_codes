#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x   = 0;  //, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        // if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x  = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x;  // * f;
}
struct day {
    int a, p, c, sold;
};
class cmp {
public:
    bool operator()(day const &a, day const &b) { return a.p > b.p; }
    // greater cmp makes a smallest on top heap
};
int main() {
    int n = read();
    day d[n], input;
    priority_queue<day, vector<day>, cmp> q;
    for (int i = 0; i < n; i++) {
        d[i].a = read();
        d[i].p = read();
        d[i].c = read();
    }
    long long inventory = max(0, d[0].a - d[0].c);  //, sold = d[0].c;
    d[0].sold           = min(d[0].a, d[0].c);
    q.push(d[0]);
    for (int i = 1; i < n; i++) {
        inventory += d[i].a;
        day qt;
        d[i].sold = min(inventory, (long long)d[i].c);
        inventory -= d[i].sold;
        if (inventory == 0) {
            int demand = d[i].c - d[i].sold;
            while (demand > 0 and !q.empty()) {
                qt = q.top();
                if (qt.p >= d[i].p) break;
                q.pop();
                int move_sold = min(qt.sold, demand);
                demand -= move_sold;
                qt.sold -= move_sold;
                d[i].sold += move_sold;
                if (qt.sold > 0) q.push(qt);
            }
        }
        // cout << "day " << i << ":" << d[i].sold << endl;
        q.push(d[i]);
    }
    long long gain = 0;
    while (!q.empty()) {
        // cout << q.top().p << " " << q.top().sold << endl;
        gain += q.top().p * q.top().sold;
        q.pop();
    }
    cout << gain;
}

