#include <bits/stdc++.h>
using namespace std;
struct book {
    int w, h;
};
bool operator<(book const &a, book const &b) {
    if (a.w != b.w)
        return a.w < b.w;
    else
        return a.h < b.h;
}
// struct node {
//     int ttl_in;
//     vector<int> to;
// };
// node a[5005];
book b[5005];
int n, cnt;  //, paired[5005];
// vector<int> todo, next_todo;
// stack<int> h[10001];
// int picked[5005];
multiset<int> stacks;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &b[i].w, &b[i].h);
    }
    sort(b, b + n);
    stacks.insert(b[0].h);
    for (int i = 1; i < n; i++) {
        auto it = stacks.lower_bound(b[i].h);
        if (it == stacks.end()) {
            it--;
            stacks.erase(it);
            stacks.insert(b[i].h);
        } else if (it == stacks.begin() and *it > b[i].h)
            stacks.insert(b[i].h);
        else if (it != stacks.begin() and *it > b[i].h) {
            stacks.erase(--it);
            stacks.insert(b[i].h);
        }
    }
    printf("%d\n", stacks.size());
    // for (int i = 1; i < 10; i++) stacks.insert(i);
    // auto it = stacks.upper_bound(10);
    // cout << (it == stacks.end() ? 1 : 0) << *it << endl;
    // for (int i = 0; i < n; i++) h[b[i].h].push(i);
    // for (int i = n - 1; i >= 0; i--) {
    //     if (picked[i]) continue;
    //     cnt++;
    //     int now_h = b[i].h, now_i = i;
    //     while (now_i > 0 and now_h > 0) {
    //         if (!h[now_h].empty()) {
    //             if (now_i >= h[now_h].top()) {
    //                 now_i = h[now_h].top();
    //                 h[now_h].pop();
    //                 picked[now_i] = true;
    //             } else {
    //                 now_h--;
    //             }
    //         } else
    //             now_h--;
    //     }
    // }

    // for (int now_h=b[i].h;now_h>0;now_h--){
    // vector<int> a;
    // for (int i = 0; i < n; i++) a.push_back(b[i].h);
    // while (a.size() > 2) {
    //     remove_last(a);
    //     // cout << a.size() << " ";
    //     cnt++;
    // }
}
// for (int i = 1; i <= n; i++) {
//     if (b[i].h > b[i + 1].h) tail++;
//     // while (tail > 0 and b[s[tail]].h <= b[i].h) tail--;
//     // s[++tail] = i;
// }

// for (int i = 0; i < todo.size(); i++) {
//     bool found_son = false;
//     for (int j : a[todo[i]].to) {
//         if (paired[j] == 3) continue;
//         if (paired[j] == 2) {
//             paired[j] = 3;
//             found_son = true;
//             break;
//         }
//         if (paired[j] == 0) {
//             found_son = true;
//             break;
//         }
//     }
//     if (!found_son) cnt++;
// }
// for (int i = 0; i < n; i++)
//     for (int j = i + 1; j < n; j++)
//         if (b[j].w >= b[i].w and b[j].h >= b[i].h) {
//             a[j].to.push_back(i);
//             a[i].ttl_in++;
//         }
// for (int i = 0; i < n; i++)
//     if (a[i].ttl_in == 0) todo.push_back(i);  // todo[++todo_cnt] = (i);
// // cnt = todo.size();
// while (todo.size()) {
//     for (int i = 0; i < todo.size(); i++) {
//         node now = a[todo[i]];
//         for (int j : now.to)
//             if ((--a[j].ttl_in) == 0) {
//                 next_todo.push_back(j);
//                 // paired[j] = 2;
//             }
//     }
//     swap(next_todo, todo);
//     next_todo.clear();
// }
// void remove_LIS(vector<int> &a) {
//     for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
//     cout << endl;
//     vector<int> work(a.begin(), a.end());
//     int picked[a.size()], father[a.size()], f[a.size()], max_ttl = 0,
//     max_tail; for (int i = 0; i < a.size(); i++) {
//         int max_f = 0, prev = 0;
//         for (int j = 0; j < i; j++) {
//             if (work[j] <= work[i] and f[j] > max_f) max_f = f[j];
//             prev = j;
//         }
//         f[i]      = max_f + 1;
//         father[i] = prev;
//         if (f[i] > max_ttl) {
//             max_ttl  = f[i];
//             max_tail = i;
//         }
//     }
//     for (int i = 0; i < a.size(); i++) cout << f[i] << " ";
//     cout << endl;
//     memset(picked, 0, sizeof(picked));
//     while (max_tail) {
//         picked[max_tail] = 1;
//         max_tail         = father[max_tail];
//     }
//     a.clear();
//     for (int i = 0; i < work.size(); i++)
//         if (!picked[i]) a.push_back(work[i]);
//     for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
//     cout << endl;
// }
//
