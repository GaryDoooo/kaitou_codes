#include <iostream>
using namespace std;
int n, sum, a = 1e9;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        a = min(a, temp);
        sum += a;
    }
    cout << sum;
}