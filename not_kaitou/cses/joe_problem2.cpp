#include <iostream>
using namespace std;
int prv[212345], n, k, nxt[212345];
int main() {
    cin >> n >> k;
    // cout << n << k << endl;
    for (int i = 1; i <= n; i++) {
        prv[i] = i - 1;
        nxt[i] = i + 1;
    }
    prv[1] = n;
    nxt[n] = 1;
    int i  = 1;
    while (nxt[i] != i) {
        for (int j = 0; j < k % n; j++) i = nxt[i];
        cout << i << " ";
        prv[nxt[i]] = prv[i];
        nxt[prv[i]] = nxt[i];
        i           = nxt[i];
        n--;
    }
    cout << i << endl;
}
