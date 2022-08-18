#include <bits/stdc++.h>
using namespace std;
int n, w[212345], d[212345];
long long check2(long long limit) {
    vector<int> pos;
    long long seg_cost = 0, now_weight = 0, ttl_cost = 0;
    for (int i = 1; i <= n; i++) {
        now_weight += w[i];
        seg_cost += now_weight * d[i];
        if (seg_cost > limit) {
            pos.push_back(i);
            ttl_cost += seg_cost - now_weight * d[i];
            seg_cost   = 0;
            now_weight = 0;
        }
    }
    long long res = 2e18;
    for (int offset1 = -5; offset1 <= 5; offset1++) {
        int p1 = pos[0] + offset1;
        if (p1 < 1 or p1 > n) continue;
        for (int offset2 = -5; offset2 <= 5; offset2++) {
            int p2 = pos[1] + offset2;
            if (p2 < 1 or p2 > n or p2 < p1) continue;
            seg_cost = now_weight = ttl_cost = 0;
            for (int i = 1; i <= n; i++) {
                now_weight += w[i];
                seg_cost += now_weight * d[i];
                if (i == p1 or i == p2) {
                    ttl_cost += seg_cost - now_weight * d[i];
                    seg_cost   = 0;
                    now_weight = 0;
                }
            }
            ttl_cost += seg_cost;
            res = min(res, ttl_cost);
        }
    }
    return res;
}

long long check(long long limit) {
    int cnt            = 0;
    long long seg_cost = 0, now_weight = 0, ttl_cost = 0;
    for (int i = 1; i <= n; i++) {
        // if (limit == 8) {
        //     cout << seg_cost << " " << now_weight << " " << cnt << " " <<
        //     w[i]
        //          << " " << d[i] << endl;
        // }

        now_weight += w[i];
        seg_cost += now_weight * d[i];
        if (seg_cost > limit) {
            if (cnt >= 2) return -1;
            cnt++;
            ttl_cost += seg_cost - now_weight * d[i];
            seg_cost   = 0;
            now_weight = 0;
        }
    }
    ttl_cost += seg_cost;
    return ttl_cost;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", w + i, d + i);
    long long left = 0, right = 2e9;
    while (left < right) {
        long long mid = (left + right) / 2;
        // cout << mid << " " << check(mid) << endl;
        if (check(mid) >= 0)
            right = mid;
        else
            left = mid + 1;
    }
    cout << check2(right) << endl;
    // cout << right << " " << left << endl;
}

