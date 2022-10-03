#include <iostream>
using namespace std;
int n, a[212345], q[212345], ans[212345], head = 1, tail;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) {
        while (head <= tail and a[q[tail]] > a[i]) {
            ans[q[tail]] = i;
            tail--;
        }
        q[++tail] = i;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
