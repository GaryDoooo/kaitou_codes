#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int sum[s.length() + 1];
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i < s.length(); i++)
        sum[i] = sum[i - 1] + (s[i] == s[i - 1]);
    sum[s.length()] = sum[s.length() - 1];
    int q, a, b;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        if (b == s.length())
            printf("%d\n", sum[b] - sum[a - 1]);
        else
            printf("%d\n", sum[b] - sum[a - 1] - (s[b] == s[b - 1]));
    }
    // for (int i = 1; i <= s.length(); i++) cout << sum[i] << " ";
}
