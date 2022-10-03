#include <cmath>
#include <stdio.h>
using namespace std;
inline int read() {
    int x = 0;//；//, f = 1;
    char ch = getchar();
    // while (!isdigit(ch)) {if (ch == '-')f = -1; ch = getchar();}
    while ((ch = getchar()) > 47) {x = (x << 1) + (x << 3) + (ch ^ 48);}
    return x ;
}
inline void write(int x) {
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48);  // 48 是 '0'
}
int main() {
    register int t, n, a;
    t = read();
    t = t << 1;
    for (n = sqrt(t); n >= 2; n --) {
        if (t % n == 0) {
            a = t / n  - n + 1;
            if (!(a & 1)) {
                a = a >> 1;
                // cout << a << " " << a + n - 1 << "\n";
                write(a); putchar(' '); write(a + n - 1); putchar('\n');
            }
        }
    }
    return 0;
}