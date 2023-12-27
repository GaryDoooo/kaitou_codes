#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MIN_INT -2147483648
using namespace std;
typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unordered_set<int> usint;
inline int read() {
    int xxxxx = 0, fffff = 1;
    char ccccch = getchar();
    while (!isdigit(ccccch)) {
        if (ccccch == '-') fffff = -1;
        ccccch = getchar();
    }
    while (isdigit(ccccch)) {
        xxxxx  = (xxxxx << 1) + (xxxxx << 3) + (ccccch ^ 48);
        ccccch = getchar();
    }
    return xxxxx * fffff;
}
inline void write(int x) {
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48);  // 48 是 '0'
    putchar(' ');
}
////////////////////////

int main() {
    int n = read(), m = read(), k = read();
    priority_queue<int, vector<int>, less<int>> q;
    int desired[n];
    for (int i = 0; i < n; i++) desired[i] = read();
    for (int i = 0; i < m; i++) q.push(read());
    sort(desired, desired + n);
    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (q.empty()) break;
        if (desired[i] > q.top() + k) continue;
        while (q.top() - k > desired[i] and (!q.empty())) q.pop();
        if (q.empty()) break;
        if (desired[i] > q.top() + k) continue;
        res++;
        q.pop();
    }
    write(res);
}
