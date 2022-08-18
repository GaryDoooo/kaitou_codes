#include <bits/stdc++.h>
using namespace std;
int a[1000006], t, n, m_index, temp;
map<int, int> m;
int get_root(int index) {
    int i = index;
    while (a[index]) index = a[index];
    if (i == index) return i;
    return a[i] = index;
}
void combine(int i1, int i2) {
    int r1 = get_root(i1), r2 = get_root(i2);
    if (r1 != r2) a[r1] = r2;
}

int get_index(int i) {
    if ((temp = m[i]) == 0) return m[i] = ++m_index;
    return temp;
}

bool test() {
    memset(a, 0, sizeof(a));
    m.clear();
    m_index = 0;
    stack<int> not_equal;
    int ii, jj, ee;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &ii, &jj, &ee);
        int i1 = get_index(ii), i2 = get_index(jj);
        if (ee)
            combine(i1, i2);
        else {
            not_equal.push(i1);
            not_equal.push(i2);
        }
    }
    while (!not_equal.empty()) {
        int r1 = get_root(not_equal.top());
        not_equal.pop();
        int r2 = get_root(not_equal.top());
        not_equal.pop();
        if (r1 == r2) return false;
    }
    return true;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (test())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}

