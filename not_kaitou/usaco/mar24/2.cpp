#include <bits/stdc++.h>
using namespace std;
int n, p, x[212345], y[212345], idx, vis[212345], res[212345];
multiset<pair<int, int>> xi, yi, xe, ye;
vector<int> path;
long long total_len, dis[212345], gap[212345];
vector<pair<long long, long long>> ps;
// first long long is dis,
// 2nd 0 is ending, 1 is start, 2 is post
vector<int> get_points(multiset<pair<int, int>> &s, int x) {
    auto it = s.lower_bound(make_pair(x, 0));
    vector<int> res;
    while (it->first == x) {
        res.push_back(it->second);
        it++;
    }
    return res;
}

bool cmpy(int a, int b) { return y[a] < y[b]; }
bool cmpx(int a, int b) { return x[a] < x[b]; }

void tracing(int index, int dir, int step) {
    int next_i, next_dir;
    if (step > p) return;
    vis[index] = 1;
    path.push_back(index);
    if (dir == 2) {
        vector<int> i0 = get_points(xi, x[index]);
        bool found     = false;
        sort(i0.begin(), i0.end(), cmpy);
        auto it = lower_bound(i0.begin(), i0.end(), index, cmpy);
        int ii  = distance(i0.begin(), it);
        // for (int i = 0; i < i0.size(); i++)
        //     if (i0[i] == index) {
        //         ii = i;
        //         break;
        //     }
        for (int j = ii + 1; j < i0.size(); j++)
            if (!vis[i0[j]]) {
                next_i   = i0[j];
                next_dir = 1;
                found    = true;
                break;
            }
        if (!found)
            for (int j = ii - 1; j >= 0; j--)
                if (!vis[i0[j]]) {
                    next_i   = i0[j];
                    next_dir = 3;
                    found    = true;
                    break;
                }
    } else if (dir == 0) {
        vector<int> i0 = get_points(xi, x[index]);
        sort(i0.begin(), i0.end(), cmpy);
        auto it = lower_bound(i0.begin(), i0.end(), index, cmpy);
        int ii  = distance(i0.begin(), it);
        // for (int i : i0) cout << i << " ";
        // cout << endl;
        bool found = false;
        // int ii     = 0;
        // for (int i = 0; i < i0.size(); i++)
        //     if (i0[i] == index) {
        //         ii = i;
        //         break;
        //     }
        // cout << ii << endl;
        for (int j = ii - 1; j >= 0; j--)
            if (!vis[i0[j]]) {
                next_i   = i0[j];
                next_dir = 3;
                found    = true;
                break;
            }
        if (!found)
            for (int j = ii + 1; j < i0.size(); j++)
                if (!vis[i0[j]]) {
                    next_i   = i0[j];
                    next_dir = 1;
                    found    = true;
                    break;
                }
        // cout << next_i << endl;

    } else if (dir == 1) {
        vector<int> i0 = get_points(yi, y[index]);
        bool found     = false;
        sort(i0.begin(), i0.end(), cmpx);
        auto it = lower_bound(i0.begin(), i0.end(), index, cmpx);
        int ii  = distance(i0.begin(), it);
        // int ii = 0;
        // for (int i = 0; i < i0.size(); i++)
        //     if (i0[i] == index) {
        //         ii = i;
        //         break;
        //     }
        for (int j = ii - 1; j >= 0; j--)
            if (!vis[i0[j]]) {
                next_i   = i0[j];
                next_dir = 2;
                found    = true;
                break;
            }
        if (!found)
            for (int j = ii + 1; j < i0.size(); j++)
                if (!vis[i0[j]]) {
                    next_i   = i0[j];
                    next_dir = 0;
                    found    = true;
                    break;
                }
    } else {
        vector<int> i0 = get_points(yi, y[index]);
        bool found     = false;
        sort(i0.begin(), i0.end(), cmpx);
        auto it = lower_bound(i0.begin(), i0.end(), index, cmpx);
        int ii  = distance(i0.begin(), it);
        // int ii = 0;
        // for (int i = 0; i < i0.size(); i++)
        //     if (i0[i] == index) {
        //         ii = i;
        //         break;
        //     }
        for (int j = ii + 1; j < i0.size(); j++)
            if (!vis[i0[j]]) {
                next_i   = i0[j];
                next_dir = 0;
                found    = true;
                break;
            }
        if (!found)
            for (int j = ii - 1; j >= 0; j--)
                if (!vis[i0[j]]) {
                    next_i   = i0[j];
                    next_dir = 2;
                    found    = true;
                    break;
                }
    }
    // cout << next_i << " " << next_dir << endl;
    tracing(next_i, next_dir, step + 1);
}

long long get_dis(int xx, int yy) {
    vector<int> i0 = get_points(xe, xx);
    for (int i : i0)
        if (y[path[i]] <= yy and y[path[i + 1]] >= yy or
            y[path[i + 1]] <= yy and y[path[i]] >= yy)
            return dis[i] + abs(yy - y[path[i]]);
    vector<int> i1 = get_points(ye, yy);
    for (int i : i1)
        if (x[path[i]] <= xx and x[path[i + 1]] >= xx or
            x[path[i + 1]] <= xx and x[path[i]] >= xx)
            return dis[i] + abs(xx - x[path[i]]);
}

int main() {
    scanf("%d %d", &n, &p);
    for (int i = 1; i <= p; i++) {
        scanf("%d %d", x + i, y + i);
        xi.insert(make_pair(x[i], i));
        yi.insert(make_pair(y[i], i));
    }

    int x0         = xi.begin()->first;
    vector<int> i0 = get_points(xi, x0);
    idx            = i0[0];
    int y0         = y[i0[0]];
    for (int i : i0)
        if (y[i] < y0) {
            y0  = y[i];
            idx = i;
        }
    // cout << idx << endl;
    tracing(idx, 0, 1);
    path.push_back(path[0]);
    // for (int i : path) cout << i << " ";
    for (int i = 1; i < path.size(); i++) {
        if (x[path[i]] == x[path[i - 1]]) {
            gap[i] = abs(y[path[i - 1]] - y[path[i]]);
            xe.insert(make_pair(x[path[i - 1]], i - 1));
        } else {
            gap[i] = abs(x[path[i - 1]] - x[path[i]]);
            ye.insert(make_pair(y[path[i - 1]], i - 1));
        }
        dis[i] = dis[i - 1] + gap[i];
    }
    total_len = dis[path.size() - 1];
    // path.pop_back();
    // cout << total_len << endl;
    for (int i = 0; i < path.size() - 1; i++)
        ps.push_back(make_pair(dis[i], 2));
    for (int i = 1; i <= n; i++) {
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        long long d1 = get_dis(x1, y1), d2 = get_dis(x2, y2);
        // cout << d1 << " " << d2 << endl;
        if (d1 > d2) swap(d1, d2);
        long long inner = d2 - d1;
        long long outer = total_len - inner;
        if (inner < outer) {
            ps.push_back(make_pair(d1, 1));
            ps.push_back(make_pair(d2, 0));
        } else {
            ps.push_back(make_pair(0, 1));
            ps.push_back(make_pair(d1, 0));
            ps.push_back(make_pair(d2, 1));
            ps.push_back(make_pair(total_len, 0));
        }
    }
    sort(ps.begin(), ps.end());
    // for (auto i : ps) cout << i.first << "..." << i.second << endl;
    int cow = 0, post_i = 0;
    for (int i = 0; i < ps.size();) {
        long long d = ps[i].first;
        int cow_in = 0, cow_out = 0;
        vector<int> posts;
        while (ps[i].first == d and i < ps.size()) {
            int type = ps[i].second;
            if (type == 0)
                cow_out++;
            else if (type == 1)
                cow_in++;
            else
                posts.push_back(post_i++);
            i++;
        }
        for (int j : posts) {
            // cout << "post" << j << endl;
            res[path[j]] = cow + cow_in;
        }
        cow = cow + cow_in - cow_out;
    }
    for (int i = 1; i <= p; i++) printf("%d\n", res[i]);
}
