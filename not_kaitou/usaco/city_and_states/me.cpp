#include <bits/stdc++.h>
using namespace std;
int n;
int a[700][700];

int main() {
    scanf("%d", &n);
    string tempc, temps;
    for (int i = 1; i <= n; i++) {
        cin >> tempc >> temps;
        if (tempc[0] == temps[0] && tempc[1] == temps[1]) continue;
        int city  = (int)(tempc[0] - 'A') + (int)(tempc[1] - 'A') * 26;
        int state = (int)(temps[0] - 'A') + (int)(temps[1] - 'A') * 26;
        a[city][state]++;
    }
    int ans = 0;
    for (int city = 0; city < 26 * 26; city++)
        for (int state = 0; state < 26 * 26; state++)
            ans += a[state][city] * a[city][state];
    printf("%d\n", ans / 2);
    return 0;
}
