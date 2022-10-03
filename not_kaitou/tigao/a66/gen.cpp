#include <bits/stdc++.h>
using namespace std;
int rndnext(int s, int e) { return rand() % e + s; }
int main() {
    srand(time(NULL));
    int t = rndnext(1, 1000);
    int m = t;
    int n = rndnext(1, 100);
    int k = rndnext(1, m);
    printf("%d %d %d\n", n, t, k);
    for (int i = 1; i <= n; i++) {
        int v = rndnext(1, 1000000);
        int h = rndnext(1, t / 5);
        printf("%d %d\n", v, 5 * h);
    }
}
