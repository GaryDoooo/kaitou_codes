#include <iostream>
using namespace std;
int a[20005], i, n;
int main() {
    cin >> n;
    long long j = 0;
    for (i = 1; j < n; i++)
        for (int k = 0; k < i; k++) a[++j] = i;
    j = 0;
    for (int k = 1; k <= n; k++) j += a[k];
    cout << j << endl;
}
