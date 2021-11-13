#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");
    int c[3], m[3];
    for (int i = 0; i < 3; i++) {
        fin >> c[i] >> m[i];
    }
    int from = 0, to = 1;
    for (int i = 0; i < 100; i++) {
        if (m[from] + m[to] > c[to]) {
            m[from] = m[from] + m[to] - c[to];
            m[to]   = c[to];
        } else {
            m[to] += m[from];
            m[from] = 0;
        }
        from = (from + 1) % 3;
        to   = (to + 1) % 3;
    }
    for (int i = 0; i < 3; i++) fout << m[i] << endl;
}
