#include<bits/stdc++.h>
using namespace std;
int main() {
    int h, w, a[50000] = {0}, i = 0;
    cin >> h >> w;
    while (cin >> a[i]) i++;
    int direction[4] = {w, 1, -w, -1}, d = 0;
    i = 0;
    for (int count = 1 ; count <= h * w; count++) {
        cout << a[i] << " ";
        a[i] = -1;
        if (count == h) {d = 1; i += 1; continue;}
        if (count == h + w - 1) {d = 2; i -= w; continue;}
        if (count == h + w + h - 2) {d = 3; i -= 1; continue;}
        int new_i = i + direction[d];
        if (a[new_i] == -1) {
            d = (d + 1) % 4;
            i = i + direction[d];
        } else {
            i = new_i;
        }
    }
    return 0;
}