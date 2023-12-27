#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MIN_INT -2147483648
using namespace std;
typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unordered_set<int> usint;
inline int read() {
    int xxxxx = 0, fffff = 1;
    char ccccch = getchar();
    while (!isdigit(ccccch)) {
        if (ccccch == '-') fffff = -1;
        ccccch = getchar();
    }
    while (isdigit(ccccch)) {
        xxxxx  = (xxxxx << 1) + (xxxxx << 3) + (ccccch ^ 48);
        ccccch = getchar();
    }
    return xxxxx * fffff;
}
////////////////////////

int main() {
    struct guest {
        int a, b, i;
        bool operator>(const guest& o) const { return a > o.a; }
    };
    struct room {
        int lastday, room_number;
        bool operator<(const room& o) const { return lastday < o.lastday; }
    };
    priority_queue<guest, vector<guest>, greater<guest>> q;
    int n = read();
    for (int i = 1; i <= n; i++) {
        q.push({read(), read(), i});
    }
    multiset<room> lastday;
    int res[n + 1];
    lastday.insert({q.top().b, 1});
    res[q.top().i] = 1;
    q.pop();
    while (!q.empty()) {
        auto it = lastday.lower_bound({q.top().a, 1});
        if (it == lastday.begin()) {
            lastday.insert({q.top().b, lastday.size() + 1});
            res[q.top().i] = lastday.size();
            q.pop();
        } else {
            it--;
            res[q.top().i] = it->room_number;
            lastday.erase(it);
            lastday.insert({q.top().b, res[q.top().i]});
            q.pop();
        }
    }
    cout << *max_element(res + 1, res + n) << endl;
    for (int i = 1; i <= n; i++) cout << res[i] << " ";
    cout << endl;
}

