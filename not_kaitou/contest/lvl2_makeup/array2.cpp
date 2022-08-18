#include <iostream>
using namespace std;
int a[1000], n, cnt, p;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) continue;
        if (a[i - 1] > a[i]) {
            cnt++;
            if (p == 0) p = i - 1;
        }
    }
    cout << cnt << " " << p;
}

