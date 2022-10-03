#include <bits/stdc++.h>
using namespace std;
int shine_number(vector<int> &a) {
    int first_occurrence[101] = {0}, aggregate_dist[101] = {0}, value_read;
    for (int i = 1; i <= a.size(); i++) {
        value_read = a[i - 1];
        if (first_occurrence[value_read] == 0)
            first_occurrence[value_read] = i;
        else
            aggregate_dist[value_read] += i - first_occurrence[value_read];
    }
    return *max_element(aggregate_dist , end(aggregate_dist));
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(a.rbegin(), a.rend());
    cout << max(shine_number(a), shine_number(b));
}