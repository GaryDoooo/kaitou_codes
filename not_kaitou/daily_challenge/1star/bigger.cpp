#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n], x;
    for (int i = 0; i < n; i++) cin >> a[i];
    int res = 0;
    cin >> x;
    for (int i = 0; i < n; i++) res += (x < a[i]);
    cout << res;
}
