#include <bits/stdc++.h>
#define ll __int128
using namespace std;
int a[250], n, res;
stack<int> s;
void stack_push(int i) {
    if (s.empty())
        s.push(i);
    else if (s.top() == i) {
        s.pop();
        stack_push(i + 1);
    } else {
        s.push(i);
    }
}
int scan(int start) {
    for (int i = start; i < n; i++) stack_push(a[i]);
    int res = 0;
    while (!s.empty()) {
        res = max(res, s.top());
        s.pop();
    }
    return res;
}
// int p = 0, tp;
// for (int i = start; i < n; i++) {
//     if (p == 0) {
//         ll k      = 1;
//         node[p++] = k << (41 - a[i]);
//     } else {
//         if (a[i] > a[i - 1]) {
//             ll pp    = node[p - 1];
//             bool bad = false;
//             for (int j = a[i - 1]; j < a[i]; j++) {
//                 if (!(pp & 1)) {
//                     bad = true;
//                     break;
//                 }
//                 pp >>= 1;
//             }
//             if (bad) break;
//
//         }

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) res = max(res, scan(i));
    cout << res << endl;
}
