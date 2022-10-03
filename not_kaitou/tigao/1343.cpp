#include <bits/stdc++.h>
using namespace std;
struct coupon {
    int time, price, available = 1;
};
coupon q[112345];
int n, type, time_, price, head = 1, tail, cost;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &type, &price, &time_);
        while (head <= tail and q[head].time + 45 < time_) head++;
        if (type == 0) {
            cost += price;
            q[++tail].time = time_;
            q[tail].price  = price;
            // = {.time = time_, .price = price};
        } else {
            bool found = false;
            for (int j = head; j <= tail; j++) {
                if (q[j].price >= price and q[j].available) {
                    found          = true;
                    q[j].available = 0;
                    break;
                }
            }
            if (found) continue;
            cost += price;
        }
        // cout << cost << endl;
    }
    cout << cost << endl;
}

