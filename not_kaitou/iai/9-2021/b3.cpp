#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int prev_price = 1e8, current_price;
    for (int i = 0; i < n; i++) {
        cin >> current_price;
        if (current_price > prev_price) {
            int holding = m / prev_price;
            m += holding * current_price - holding * prev_price;
        }
        prev_price = current_price;
        // cout << m << endl;
    }
    cout << m;
}

