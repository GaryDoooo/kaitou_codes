#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x  = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x;
}
struct pairs {
    int a, b, hate;
    bool operator<(const pairs& other) const { return hate > other.hate; }
};
int get_head(const int a[], int i) {
    while (a[i] != i) i = a[i];
    return i;
}
int main() {
    int n = read(), m = read();
    pairs p[m];
    for (int i = 0; i < m; i++)
        p[i].a = read(), p[i].b = read(), p[i].hate = read();
    sort(p, p + m);
    int stack_pointer[n + 1];
    for (int i = 0; i <= n; i++) stack_pointer[i] = i;
    int counter[n + 1];
    memset(counter, 255, sizeof(counter));
    for (int i = 0; i < m; i++) {
        int a = p[i].a, b = p[i].b;
        if (counter[a] < 0 and counter[b] < 0) {
            counter[a] = b;
            counter[b] = a;
            continue;
        }
        if (counter[a] < 0) swap(a, b);
        if (counter[b] < 0) {
            counter[b]       = a;
            stack_pointer[b] = get_head(stack_pointer, counter[a]);
            continue;
        }
        int a_head = get_head(stack_pointer, a),
            b_head = get_head(stack_pointer, b);
        if (a_head == b_head) {
            cout << p[i].hate;
            return 0;
        }
        if (counter[a_head] == b_head and counter[b_head] == a_head) continue;
        int counter_a_head            = get_head(stack_pointer, counter[a]);
        int counter_b_head            = get_head(stack_pointer, counter[b]);
        stack_pointer[b_head]         = counter_a_head;
        stack_pointer[counter_b_head] = a_head;
    }
    cout << 0;
}
