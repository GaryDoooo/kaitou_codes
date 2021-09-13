#include <bits/stdc++.h>
using namespace std;
int main() {
    int w[20005], v[20005], index = 0, ww, vv, s, n, maxw;
    cin >> n >> maxw;
    int b[maxw + 1];
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; i++) {
        cin >> ww >> vv >> s;
        int base = 1; //,temp=s;
        while ((base << 1) - 1 < s) {
            w[index] = base * ww;
            v[index++] = base * vv;
            base = base << 1;
        }
        w[index] = (s - (base) + 1) * ww;
        v[index++] = (s - (base) + 1) * vv;
    }
    // for (int i = 0; i < index; i++) cout << w[i] << " " << v[i] << endl;
    for (int i = 0; i < index; i++) {
        for (int j = maxw; j >= w[i]; j--) {
            b[j] = max(b[j], v[i] + b[j - w[i]]);
        }
    }
    cout << *max_element(b, b + maxw + 1);
}