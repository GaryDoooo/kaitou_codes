#include <stdio.h>
long long s[512345], em;
// The total number of cake Elsie can get is N/2-1. There are always two cakes in the middle that Elsie can't reach at a certain step and all the step after.
// Bessie should merge these two cakes. By Bessie doing this, the best Elsie can do is to get the N/2-1 cakes from the two ends, whichever portion 
// the right and left, but makes the total max.
// 然后就是前缀和。很简单。
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
