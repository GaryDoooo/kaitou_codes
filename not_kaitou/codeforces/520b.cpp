#include <bits/stdc++.h>
using namespace std;
int step[20005], vis[20005];
int start, target;

int steps_from_strat(int x) {
    if (x == start) return 0;
    if (x <= 0 or x > 20000 or vis[x]) return 2e8;
    if (step[x]) return step[x];
    vis[x] = 1;
    if (x & 1)
        return step[x] = steps_from_strat(x + 1) + 1;
    else
        return step[x] = min(steps_from_strat(x + 1) + 1,
                             steps_from_strat(x / 2) + 1);
}

int main() {
    scanf("%d %d", &start, &target);
    printf("%d\n", steps_from_strat(target));
}
