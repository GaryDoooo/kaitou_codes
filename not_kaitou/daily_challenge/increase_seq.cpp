#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-')f = -1; getchar();}
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x * f;
}
int main() {
    int n = read();
    unordered_map<int, int> m;
    int a[n], l[n], m2[n], na[n];
    for (int i = 0; i < n; i++) a[i] = read(), m[a[i]] = i;
    memset(l, 0, sizeof(l));
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        int current_pos = m[a[i]];
        m2[i] = current_pos;
        for (int j = i - 1; j >= 0; j--) {
            if (m2[j] < current_pos) {
                l[i] = l[j] + 1;
                break;
            }
        }
    }
    cout << *max_element(l, l + n) + 1;
}