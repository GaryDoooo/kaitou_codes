#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0;//, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {/*if (ch == '-')f = -1; */ch = getchar();}
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x;// * f;
}
int main() {
    register int n = read(), minimum = 1e9, res = 0, r;
    for (register int i = 0; i < n; i++) {
        r = read();
        minimum = min(minimum, r);
        res = max(r - minimum, res);
    }
    cout << res;
}