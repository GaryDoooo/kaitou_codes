#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
bool is_prime(int n) {
    if (n == 2) return true;
    for (int i = 2; i < sqrt(n) + 1; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int main() {
    int L = 6;
    // cin >> L;
    int sum = 0;
    vector<int> res = {};
    for (int i = 2; i < L; i++) {
        if (is_prime(i)) {
            if (sum + i > L) {
                break;
            }
            res.push_back(i);
            sum += i;
        }
    }
    for (auto i : res) cout << i << "\n";
    cout << res.size();
}