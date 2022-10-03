#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, r0;
    cin >> n >> r0;
    int r[n];
    r[0] = r0;
    for (int i = 1; i < n; i++) {
        r[i] = (r[i - 1] * 6807 + 2831) % 201701;
    }
    for (int i = 0; i < n; i++)r[i] = r[i] % 10;
    int water_depth[n];
    memset(water_depth, 0, sizeof(water_depth));
    for (int i = 0; i < n; i++) {
        for (int d = r[i]; d < 10; d++) {
            bool left_bound = false, right_bound = false;
            for (int j = 0; j < i; j++) {if (r[j] >= d) {left_bound = true; break;}}
            for (int j = i + 1; j < n; j++) if (r[j] >= d) {right_bound = true; break;}
            if (left_bound && right_bound) water_depth[i] = d - r[i];
        }
    }
    cout << accumulate(water_depth, water_depth + n, 0);
    // for (int i = 0; i < n; i++) cout << r[i] << " ";
    // cout << endl;
    // int current_height = 0;
    // vector<int> maximum;
    // bool up = true;
    // for (int i = 0; i < n; i++) {
    //     if (r[i] > current_height) up = true;
    //     if (r[i] < current_height) {
    //         if (up) maximum.push_back(i - 1);
    //         up = false;
    //     }
    //     current_height = r[i];
    // }
    // if (up) maximum.push_back(n - 1);
    // // for (auto i : maximum) cout << r[i] << " ";
    // // cout << endl;
    // int right = 0, res = 0, res2 = 0;
    // for (auto i : maximum) {
    //     if (i < right) continue;
    //     int left = i, res_temp = 0;
    //     for (right = i + 1; right < n; right++) {
    //         if (r[right] >= r[left]) break;
    //         res_temp += r[left] - r[right];
    //     }
    //     if (right >= n - 1) break;
    //     res += res_temp;
    // }
    // right = n - 1;
    // for (int j = maximum.size() - 1; j >= 0; j--) {
    //     int         i = maximum[j];
    //     if (i > right) continue;
    //     int left = i, res_temp = 0;
    //     for (right = i - 1; right >= 0; right--) {
    //         if (r[right] >= r[left]) break;
    //         res_temp += r[left] - r[right];
    //     }
    //     if (right <= 0) break;
    //     res2 += res_temp;
    // }
    // cout << max(res, res2);
}