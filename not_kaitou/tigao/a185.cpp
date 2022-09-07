#include <bits/stdc++.h>
using namespace std;
int n, res, minimum = 50;
struct node {
    int minimum;
    vector<int> a;
};
queue<node> q;
void push_q(int m, int last_len, int len, int h_begin, int h_len) {
    node t;
    // t.minimum = m + 1;
    int m1 = m + 1;
    for (int j = 0; j < (last_len >> 1); j++) t.a.push_back(m1);
    for (int j = h_begin; j < h_begin + h_len; j++)
        if (q.front().a[j] > m)
            t.a.push_back(q.front().a[j]);
        else {
            t.a.push_back(m1);
            j++;
        }
    for (int j = 0; j < (len >> 1); j++) t.a.push_back(m1);
    if (t.a.size()) {
        t.minimum = *min_element(t.a.begin(), t.a.end());
        q.push(t);
    }
}
int main() {
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        minimum = min(a[i], minimum);
        res     = max(a[i], res);
    }
    node temp;
    temp.minimum = minimum;
    q.push(temp);
    swap(q.front().a, a);
    while (!q.empty()) {
        // if (q.front().a.size() < 300) {
        //     for (int i : q.front().a) cout << i << " ";
        //     cout << endl;
        // }
        int m        = q.front().minimum;
        int last_len = 0, len = 0, h_begin = 0, h_len = 0,
            last_a = q.front().a[0];
        res        = max(last_a, res);
        if (last_a == m)
            len = 1;
        else
            h_len = 1;
        for (int i = 1; i < q.front().a.size(); i++) {
            int a = q.front().a[i];
            res   = max(a, res);
            if (last_a == m and a == m)
                len++;
            else if (last_a == m and a > m) {
                if (len & 1) {
                    if (h_len) {
                        push_q(m, last_len, len, h_begin, h_len);
                    }
                    last_len = len;
                    h_begin  = i;
                    h_len    = 1;
                    len      = 0;
                } else {
                    h_len += len + 1;
                    len = 0;
                }
            } else if (last_a > m and a > m) {
                h_len++;
            } else if (last_a > m and a == m) {
                len = 1;
            }
            last_a = a;
        }
        push_q(m, last_len, len, h_begin, h_len);
        q.pop();
    }
    printf("%d\n", res);
}

// int a[2500000], n, res;
// stack<int> s;
// void stack_push(int i) {
//     if (s.empty())
//         s.push(i);
//     else if (s.top() != i) {
//         s.push(i);
//     } else {
//         while (s.top() == i) {
//             // if (s.top() == i) {
//             s.pop();
//             // stack_push(i + 1);
//             i++;
//             if (s.empty()) break;
//         }
//         s.push(i);
//     }
// }
// int scan(int start) {
//     for (int i = start; i < n; i++) stack_push(a[i]);
//     int res = 0;
//     while (!s.empty()) {
//         res = max(res, s.top());
//         s.pop();
//     }
//     return res;
// }
// int main() {
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) scanf("%d", a + i);
//     for (int i = 0; i < n; i++) res = max(res, scan(i));
//     // cout << res << endl;
//     printf("%d\n", res);
// }
