#include <bits/stdc++.h>
using namespace std;

// make a 1D array for N+2 by N+2 grid
int W, N, Q;
int a[2123456]; // before which step the cell
                // to be available
int o[2123456]; // the cell occupied or not
int res[212345];
int step_p[212345], step_d[212345]; // p=x+y*W

void visit(const int input_p, const int step) {
    if (a[input_p])
        return;
    stack<int> s; // using stack for dfs, cz using function will overflow since
                  // too many layers
    int d[4] = {1, -1, W, -W};
    s.push(input_p);
    a[input_p] = step;
    while (s.size()) {
        int p = s.top();
        s.pop();
        for (int i = 0; i < 4; i++) {
            int new_p = p + d[i];
            if (new_p < 0 or new_p >= W * W)
                continue;
            if (a[new_p])
                continue;
            if (o[new_p] > 0 and o[new_p] != p)
                continue;
            s.push(new_p);
            a[new_p] = step;
        }
    }
}

int is_open(int p) {
    int d[4] = {1, -1, W, -W};
    for (int i = 0; i < 4; i++) {
        int new_p = p + d[i];
        if (a[new_p])
            return 1;
    }
    return 0;
}

int main() {
    scanf("%d %d", &N, &Q);
    W = N + 2;
    map<char, int> c2d;
    c2d['L'] = -1;
    c2d['R'] = 1;
    c2d['U'] = -W;
    c2d['D'] = W;
    for (int i = 0; i < Q; i++) {
        int x, y;
        char d;
        scanf("%d %d %c", &y, &x, &d);
        step_p[i] = x + y * W;
        step_d[i] = c2d[d];
        o[step_p[i]] =
            step_p[i] +
            step_d[i]; // >0 is occupied, value is the cell pointing to
    }
    visit(0, Q + 1);
    for (int i = Q - 1; i >= 0; i--) {
        o[step_p[i]] = 0;
        if (is_open(step_p[i]))
            visit(step_p[i], i + 1); // from step #i the cell becomes unusable
    }
    for (int i = 0; i < W * W; i++)
        res[a[i]]++;
    int sum = 0;
    for (int i = 1; i <= Q; i++) {
        sum += res[i]; // total unusable cells at this step
        printf("%d\n", sum);
    }
}
