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
    int n = read();
    int pa[n + 1];
    for (int i = 0; i < n; i++) pa[read()] = i;
    int longest_head[n + 1];
    register int a, longest = 1;
    longest_head[1]  = pa[read()];
    longest_head[0] = 0; pa[0] = 0;
    for (register int i = 1; i < n; i++) {
        a = pa[read()];
        if (longest_head[longest] < a) longest_head[++longest] = a;
        auto x = upper_bound(longest_head, longest_head + longest, a);
        *x = a;
    }
    cout << longest;
}