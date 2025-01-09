#include <stdio.h>
long long s[512345], em;
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int a;
            scanf("%d", &a);
            s[i] = a + s[i - 1];
        }
        em = 0;
        for (int i = 0; i <= (n / 2) - 1; i++) {
            long long elsie = s[i] + s[n] - s[n - (n / 2 - 1 - i)];
            if (elsie > em) em = elsie;
        }
        printf("%lld %lld\n", s[n] - em, em);
    }
}
