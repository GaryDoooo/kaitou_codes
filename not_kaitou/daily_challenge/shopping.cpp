#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> &a, pair<int, int> &b) { return a.second < b.second;}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long sum, all_a_sum = 0 ;
    cin >> n;
    pair<int, int> ab[n];
    for (int i = 0; i < n; i++) cin >> ab[i].first, all_a_sum += ab[i].first ;
    for (int i = 0; i < n; i++) cin >> ab[i].second;
    int left = 0, right = n - 1, mid;
    sort(ab, ab + n, cmp);
    while (left < right) {
        mid = (left + right) / 2;
        sum = 0;
        for (int i = mid + 1; i < n; i++) sum += ab[i].first;
        if (sum > ab[mid].second) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    sum = 0;
    for (int i = left + 1; i < n; i++) sum += ab[i].first;
    cout << min(all_a_sum, max((long long)ab[left].second, sum) ) << endl;
    return 0;
}