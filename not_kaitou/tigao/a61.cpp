#include <cstring>
#include <iostream>
using namespace std;
int res[2005][2005], v[2005], n;
int earn(int item, int day) {
    if (res[item][day] >= 0) return res[item][day];
    if (day == 0 or item < 1 or item > n) return res[item][day] = 0;
    int left_sold = item - 1, right_sold = n - item;
    // if (left_sold > day - 1 and right_sold > day - 1) return -1e9;
    int left_sold_at, right_sold_at;
    if (left_sold > day - 1) {
        right_sold_at = item + 1;
        left_sold_at  = day - 1 - right_sold;
    } else {
        left_sold_at  = left_sold;
        right_sold_at = n - (day - 1 - left_sold) + 1;
    }
    return res[item][day] = day * v[item] + max(earn(right_sold_at, day - 1),
                                                earn(left_sold_at, day - 1));
}

int main() {
    memset(res, 128, sizeof(res));
    int result = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) result = max(result, earn(i, n));
    cout << result;
}
