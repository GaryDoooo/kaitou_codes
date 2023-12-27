#include <bits/stdc++.h>
using namespace std;
int main() {
    int a = 0;
    for (int i = 1; i <= 100000; i++) {
        for (int j = 0; j < 100000; j++) {
            int k = i ^ j;
            for (; k; ++a) k &= k - 1;
            // a += k;
            // while (k) a += (k & 1), k = k / 2;
        }
    }
    cout << a << endl;
}

