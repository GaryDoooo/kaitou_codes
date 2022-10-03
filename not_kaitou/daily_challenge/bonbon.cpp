#include <bits/stdc++.h>
using namespace std;
int bon(int n, int enter_one) {
    if (n == 1) return 1;
    if (n & 1) {
        if (enter_one)
            return bon(n >> 1, 0) * 2;
        else
            return bon((n >> 1) + 1, 1) * 2 - 1;
    } else {
        if (enter_one)
            return bon(n >> 1, 1) * 2;
        else
            return bon(n >> 1, 0) * 2 - 1;
    }
}
int main() {
    int n;
    cin >> n;
    cout << bon(n, 0);
}

// 1 2 3 4 5 6 7 8