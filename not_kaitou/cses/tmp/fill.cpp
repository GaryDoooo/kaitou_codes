#include <bits/stdc++.h>
using namespace std;
int p[9123456];
int main() {
    int j = 0;
    for (int i = 0; i < 256; i++) {
        memset(p, i, sizeof(p));
        fill(p, p + 9123456, i); // fill is slightly slower.
        j += p[i];
    }
    cout << j << endl;
}
