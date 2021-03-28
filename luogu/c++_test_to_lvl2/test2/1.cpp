#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool is_prime(int n) {
    if (n == 2) return true;
    if (n % 2 == 0 or n < 2) return false;
    for (int i = 3; i < sqrt(n) + 1; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> primes = {2};
    for (int i = 3; i < n; i += 2) {
        if (is_prime(i)) primes.push_back(i);
    }
    for (int i : primes) {
        for (int j : primes) {
            if (i + j == n) {
                if (i <= j) {
                    cout << i << " " << j << endl;
                }
            }
        }
    }
    return 0;
}