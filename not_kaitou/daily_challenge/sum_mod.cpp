#include <bits/stdc++.h>
using namespace std;
int main() {
    char c;
    long long space_cnt = 0, res = 0, current_mod = 0, k = 1e9 + 7;
    while ((c = getchar()) > 16) {
        if (c == ' ') {
            res = (res + current_mod) % k;
            current_mod = 0;
            space_cnt++;
        } else {
            current_mod = (current_mod * 10 + (long long)(c ^ 48)) % k;
        }
    }
    cout << space_cnt << " " << (res + current_mod) % k;
    return 0;
}