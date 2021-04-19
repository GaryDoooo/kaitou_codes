#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    ///////////////////// calc prime nums
    vector<int> primes = {2};
    for (int i = 3; i < n; i += 2) {
        bool is_prime = true;
        int stop_at   = sqrt(i);
        for (auto p = primes.begin(); p != primes.end(); p++) {
            if (i % *p == 0) {
                is_prime = false;
                break;
            }
            if (*p > stop_at) break;
        }
        if (is_prime) primes.push_back(i);
    }
    ///////////////// find pairs
    for (auto p = primes.begin(); p != primes.end(); p++) {
        if (*p > n / 2) break;
        if (binary_search(primes.begin(), primes.end(), n - *p))
            cout << *p << " " << n - *p << endl;
    }
    return 0;
}
