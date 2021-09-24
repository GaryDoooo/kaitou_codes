#include <iostream>
using namespace std;
int main() {
    int t, n;
    cin >> t >> n;
    int a, res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a > t)
            res++;
        else
            t -= a;
    }
    cout << res;
}
