#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int l, n, m, w[112345], d[112345], wi, di;
ll wft[1123456], time_len[112345];
// class cmp {
// public:
//     bool operator()(const int a, const int b) {
//         return time_len[a] > time_len[b];
//     }
// };
// priority_queue<int, multiset<int>, cmp> q, dq;
struct dryer_queue {
    ll len, cycle_time;
};
bool operator<(const dryer_queue& a, const dryer_queue& b) {
    return a.len < b.len;
}
multiset<dryer_queue> wq, dq;
// struct washer_queue {
//     ll end_time, cycle_time;
// };
// bool operator<(const washer_queue& a, const washer_queue& b) {
//     return a.end_time > b.end_time;
// }
// priority_queue<dryer_queue, vector<dryer_queue>, less<dryer_queue>> dq;
// priority_queue<washer_queue, vector<washer_queue>, less<washer_queue>> wq;
int main() {
    scanf("%d%d%d", &l, &n, &m);
    for (register int i = 0; i < n; i++) {
        scanf("%d", &wi);
        // time_len[i] = w[i];
        // q.push(i);
        wq.insert({wi, wi});
    }
    for (register int i = 0; i < l; i++) {
        // ll t = wq.top().end_time, ct = wq.top().cycle_time;
        // ll t=time_len[q.top()],ct=w[q.top()];
        // int j = q.top();
        ll t = wq.begin()->len, ct = wq.begin()->cycle_time;
        wq.erase(wq.begin());
        // q.pop();
        // wq.pop();
        // wft[i] = time_len[j];
        // time_len[j] += w[j];
        // q.push(j);
        // wq.push({t + ct, ct}) ;
        wft[i] = t;
        wq.insert({t + ct, ct});
    }
    // for (int i = 0; i < l; i++) cout << wft[i] << endl;
    // q.clear();
    for (register int i = 0; i < m; i++) {
        scanf("%d", &di);
        dq.insert({di, di});
        // time_len[i] = d[i];
        // dq.push(i);
        // dq.push({di, di});
        // empty_dq.push(di);
    }
    register ll res = 0;
    // wft[l - 1] + time_len[;
    // dq.push({dq.top().len + dq.top().cycle_time, dq.top().cycle_time});
    // dq.pop();
    for (register int i = l - 1; i >= 0; i--) {
        ll t = dq.begin()->len, ct = dq.begin()->cycle_time;
        dq.erase(dq.begin());
        res = max(res, t + wft[i]);
        dq.insert({t + ct, ct});
        // auto dryer = dq.top();
        // dq.pop();
        // int j = dq.top();
        // dq.pop();
        // res = max(res, time_len[j] + wft[i]);
        // if (res-dryer.len>=wft[i])
        // time_len[j] += d[j];
        // dq.push(j);
        // dq.push({dryer.len + dryer.cycle_time, dryer.cycle_time});
        // else

        // if (empty_dq.empty())

        // end_time_new_dryer=0;
        // else
        // end_time_new_dryer=available_time+empty_dq.top();
    }
    cout << res;
    // wq.push(1);
    // wq.push(2);
    // cout << wq.top() << endl;
    // dq.push({1, 2});
    // dq.push({3, 4});
    // dq.push({0, 1});
    // cout << dq.top().head << endl;
}
