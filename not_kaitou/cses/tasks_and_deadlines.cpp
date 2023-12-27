#include <algorithm>
#include <iostream>
using namespace std;
pair<int, int> a[212345];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    long long res = 0, t = 0;
    for (int i = 0; i < n; i++) {
        t += a[i].first;
        res += a[i].second - t;
    }
    cout << res << endl;
}
