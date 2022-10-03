#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b, res = 0;
    cin >> n >> a >> b;
    for (int i = 1; i <= n / a; i ++)
        for (int j = 1; 0 < n - i * a - j * b; j ++)
            if (i + j + n - i * a - j * b > 30)
                res++;
    cout << res;
}