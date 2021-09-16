#include <bits/stdc++.h>
using namespace std;
inline long long read() {
    long long x = 0;  //, f = 1;
    char ch     = getchar();
    while (!isdigit(ch)) {
        // if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x  = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x;  // * f;
}
// int two[205], five[205];
int n, k, res = 0;
struct number {
    int two, five;
};
number ai[205];
bool cmp(number const &a, number const &b) { return a.five > b.five; }
bool cmp2(number const &a, number const &b) { return a.two > b.two; }
int two_left[205];
int five_left[205];
void dfs(int i, int picked, int t, int f) {
    if (picked == k) {
        res = max(res, min(t, f));
        return;
    }
    if (n - i < k - picked) return;
    if (res - t > two_left[i] or res - f > five_left[i]) return;
    dfs(i + 1, picked + 1, t + ai[i].two, f + ai[i].five);
    dfs(i + 1, picked, t, f);
}

int main() {
    n = read(), k = read();
    for (int i = 0; i < n; i++) {
        long long a = read();
        // cout << a << "_";
        int t = 0, f = 0;
        while (a % 2 == 0) {
            t++;
            a /= 2;
        }
        while (a % 5 == 0) {
            f++;
            a /= 5;
        }
        ai[i].five = f;
        ai[i].two  = t;
    }
    sort(ai, ai + n, cmp2);
    int t = 0, f = 0;
    for (int i = 0; i < k; i++) {
        t += ai[i].two;
        f += ai[i].five;
    }
    res = min(t, 
            f);
    sort(ai, ai + n, cmp);
    int sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += ai[i].five;
        five_left[i] = sum;
    }
    sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += ai[i].two;
        two_left[i] = sum;
    }
    // for (int i = 0; i < n; i++) cout << two[i] << " " << five[i] << endl;
    dfs(0, 0, 0, 0);
    cout << res;
}

