#include <bits/stdc++.h>
using namespace std;
int main() {
    int sum, n = 10;
    for (int i = 0; i < 6; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            int k = j;
            while (k > 0) sum += (k % 10 == 1), k /= 10;
        }
        cout << sum << endl; //>>
        n *= 10;
    }
}