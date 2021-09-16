#include <bits/stdc++.h>
using namespace std;
struct number {
    int two, five;
};
int count_factor(long long a, int b) {
    int res = 0;
    while (a % b == 0) res++, a /= b;
    return res;
}
int main() {
    int n, k, res = 0, left_point, total_five = 0;
    long long a_in;
    cin >> n >> k;
    number a[n];
    for (int i = 0; i < n; i++) {
        cin >> a_in;
        // total_five += (
        a[i].five = count_factor(a_in, 5);  //);
        a[i].two  = count_factor(a_in, 2);
    }
    
    cout << res;
}

