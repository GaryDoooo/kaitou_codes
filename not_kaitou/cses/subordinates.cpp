#include <bits/stdc++.h>
using namespace std;

int res[212345], n;
vector<int> sons[212345];

int cnt(int x) {
    if (res[x] >= 0) return res[x];
    int sum = 0;
    for (int i : sons[x]) sum += cnt(i) + 1;
    return res[x] = sum;
}

int main() {
    scanf("%d\n", &n);
    memset(res, 128, sizeof(res));
    for (int i = 2; i <= n; i++) {
        int a;
        scanf("%d", &a);
        sons[a].push_back(i);
    }
    for (int i = 1; i <= n; i++) printf("%d ", cnt(i));
}

