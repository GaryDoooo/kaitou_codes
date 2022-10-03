#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    string d, f;
    cin >> d >> f;
    vector<int> mark(n, 0), cover_left(n, 1e9), cover_right(n, 0);
    // memset(cover_left, 100, n * sizeof(int));
    // memset(cover_right, 0, n * sizeof(int));
    // memset(mark, 0, sizeof(mark));
    for (int i = 0; i <= n - m; i++) {
        if (f == d.substr(i, m)) {
            for (int j = 0; j < m; j++) {
                mark[j + i]++;
                cover_left[j + i]  = min(cover_left[j + i], i);
                cover_right[j + i] = max(cover_right[j + i], i + m);
            }
        }
    }
    int red_cnt = 0;
    for (int i = 0; i < n; i++) red_cnt += (mark[i] > 0);
    int max_mark = *max_element(mark.begin(), mark.end());
    int lock_cnt = 0;
    for (int i = max_mark; i > 0; i--) {
        for (int j = 0; j < n; j++) {
            if (mark[j] == i) {
                lock_cnt++;
                for (int k = cover_left[j]; k < cover_right[j]; k++)
                    mark[k] = 0;
            }
        }
    }
    cout << red_cnt << " " << lock_cnt;
}
