#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool is_prime(int n) {
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i < sqrt(n) + 1; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// vector<int> splitn(int n) {
//     vector<int> res;
//     while (n > 0) {
//         int digit = n % 10;
//         n /= 10;
//         res.push_back(digit);
//     }
//     return res;
// }

// vector<int> get_primes(int n) {
//     vector<int> primes = {2};
//     for (int i = 3; i <= n; i += 2) {
//         bool is_prime = true;
//         for (auto it = primes.begin(); it != primes.end(); ++it) {
//             if (*it >= sqrt(n) + 1) break;
//             if (i % *it == 0) {
//                 is_prime = false;
//                 break;
//             }
//         }
//         if (is_prime) primes.push_back(i);
//     }
//     return primes;
// }

bool hui(int &a) {
    string sa = to_string(a);
    string r = sa;
    reverse(r.begin(), r.end());
    return (sa == r);
}

int main() {
    int min, max;
    cin >> min >> max;
    // vector<int> primes;
    // primes = get_primes(max);
////////////////////////////////
    // for (auto i = lower_bound(primes.begin(), primes.end(), min);
    //         i <= lower_bound(primes.begin(), primes.end(), max); i++) {
    //     if (i == primes.end()) break;
    //     if (hui(*i))
    //         cout << *i << endl;
    // }
    return 0;
}