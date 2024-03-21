#include <bits/stdc++.h>
using namespace std;
int n, od[212345], in_q[212345];
vector<int> e[212345];

struct longest2 {
    int d1, i1, d2, i2;
    void add(int d, int i) {
        if (d > d1) {
            swap(d1, d2), swap(i1, i2);
            d1 = d, i1 = i;
        } else if (d > d2 and i != i1) {
            d2 = d, i2 = i;
        }
    }
};

longest2 l[212345];

void add_edge(int from, int to) {
    e[from].push_back(to);
    od[from]++;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add_edge(a, b);
        add_edge(b, a);
    }
    queue<int> q;
    int last_node = 1;
    for (int i = 1; i <= n; i++)
        if (od[i] == 1) {
            q.push(i);
            in_q[i] = 1;
        }
    while (q.size()) {
        int x         = q.front();
        int longest_d = l[x].d1;
        q.pop();
        last_node = x;
        for (int i : e[x]) {
            if (in_q[i]) continue;
            l[i].add(longest_d + 1, x);
            od[i]--;
            if (od[i] == 1) {
                in_q[i] = 1;
                q.push(i);
            }
        }
    }
    memset(in_q, 0, sizeof(in_q));
    q.push(last_node);
    in_q[last_node] = 1;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int i : e[x]) {
            if (x != l[i].i1)
                l[x].add(l[i].d1 + 1, i);
            else
                l[x].add(l[i].d2 + 1, i);
            if (in_q[i]) continue;
            in_q[i] = 1;
            q.push(i);
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", l[i].d1);
}
