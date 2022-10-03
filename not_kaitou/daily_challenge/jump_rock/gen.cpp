#include <bits/stdc++.h>
#define L 1000
using namespace std;
int main() {
    // int L = 1000;
    int d[L] = {0};
    srand (time(NULL));
    for (int i = 1; i < L; i++) {d[i] = (rand() % 5 == 0);}
    int n = accumulate(d, d + L, 0);
    int m = rand() % n;
    cout << L << " " << n << " " << m << endl;
    for (int i = 0; i < L; i++) if (d[i]) cout << i << " ";
}