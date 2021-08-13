#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-')f = -1; ch = getchar();}
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x * f;
}
int main() {
    int n = read(), a;
    int mod_counter[3];
    for (int i = 0; i < n; i++) {
        a = read();
        mod_counter[a % 3]++;
    }
    cout << min(mod_counter[1], mod_counter[2]) + mod_counter[0] / 2;
    return 0;
}